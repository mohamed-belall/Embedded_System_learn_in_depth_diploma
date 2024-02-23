
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed belal
 * @Created on     : 31/8/2023
 ******************************************************************************
 */

#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_Drivers.h"
#include "STM32F103C6_EXTI_Driver.h"




uint8_t TaskA_Flag , TaskB_Flag , IRQ_Flag = 0;


#define TaskA_Stack_Size	100	//100 byte
#define TaskB_Stack_Size	100	//100 byte


extern int _estack;

// Main Stack Pointer
unsigned int *_S_MSP = &_estack;
unsigned int _E_MSP;

// Process Stack Pointer Task A
unsigned int _S_PSP_TA;
unsigned int _E_PSP_TA;

// Process Stack Pointer Task B
unsigned int _S_PSP_TB;
unsigned int _E_PSP_TB;

#define OS_SET_PSP(Address)		__asm volatile("mov r0,%0 \n\t MSR PSP,r0" : : "r" (Address))
#define OS_Switch_sp_to_PSP		__asm volatile("MRS r0,control \n\t mov r1,#0x02 \n\t ORR r0,r0,r1 \n\t MSR control,r0")
#define OS_Generate_Exception	__asm volatile("SVC #0x3")
#define OS_Switch_sp_to_MSP		__asm volatile("MRS r0,control \n\t mov r1,#0x05 \n\t AND r0,r0,r1 \n\t MSR control,r0")


enum CPUaccessLevel{
	privileged ,
	unprivileged
};




void Switch_CPU_AccessLevel(enum CPUaccessLevel level)
{
	switch(level)
	{
	case privileged:
		//clear Bit 0 : in CONTROL register
		__asm(" MRS R3,CONTROL \n\t"
				" LSR R3,R3,#0x1 \n\t"
				" LSL R3,R3,#0x1 \n\t"
				" MSR CONTROL,R3");
		break;
	case unprivileged:
		//Set Bit 0 : in CONTROL register
		__asm(" MRS R3,CONTROL \n\t"
				" ORR R3,R3,#0x1 \n\t"
				" MSR CONTROL,R3");
		break;
	}

}
void SVC_Handler()
{
	Switch_CPU_AccessLevel(privileged);
}

int TaskA(int a , int b , int c)
{
	return a+b+c;
}
int TaskB(int a , int b , int c , int d)
{
	return a+b+c+d;
}

void MainOS()
{
	// main Stack
	_E_MSP = (_S_MSP - 512);

	// PSP task A
	_S_PSP_TA = (_E_MSP - 8);
	_E_PSP_TA = (_S_PSP_TA - TaskA_Stack_Size);

	// PSP task B
	_S_PSP_TB = (_E_PSP_TA - 8);
	_E_PSP_TB = (_S_PSP_TB - TaskB_Stack_Size);

	while(1)
	{
		__asm("NOP");
		if(TaskA_Flag == 1)
		{
			// Set PSP Register = _S_PSP_TA
			OS_SET_PSP(_S_PSP_TA);

			// SP -> PSP
			OS_Switch_sp_to_PSP;

			// Switch from privileged => unprivileged
			Switch_CPU_AccessLevel(unprivileged);

			TaskA_Flag = TaskA(1,2,3);

			// Switch from unprivileged => privileged
			OS_Generate_Exception;

			// SP -> MSP
			OS_Switch_sp_to_MSP;

		}else if(TaskB_Flag == 1)
		{
			// Set PSP Register = _S_PSP_TB
			OS_SET_PSP(_S_PSP_TB);

			// SP -> PSP
			OS_Switch_sp_to_PSP;

			// Switch from privileged => unprivileged
			Switch_CPU_AccessLevel(unprivileged);

			TaskB_Flag = TaskB(1,2,3,4);

			// Switch from unprivileged => privileged
			OS_Generate_Exception;

			// SP -> MSP
			OS_Switch_sp_to_MSP;
		}
	}
}



void Clock_Init(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	//	RCC_GPIOC_CLK_EN();

}

void EXTI9_Callback(void)
{

	if(IRQ_Flag == 0)
	{
		TaskA_Flag = 1;
		IRQ_Flag   = 1;
	}else if(IRQ_Flag == 1)
	{
		TaskB_Flag = 1;
		IRQ_Flag   = 0;
	}

}


int main(void)
{

	Clock_Init();

n
	EXTI_PinConfig_t EXTI_cfg;
	EXTI_cfg.EXTI_PINS = EXTI9PB9;
	EXTI_cfg.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_cfg.P_IRQ_CallBack = EXTI9_Callback;
	EXTI_cfg.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTI_cfg);

	MainOS();
	IRQ_Flag = 1;




	while(1)
	{
		if(IRQ_Flag)
		{

			IRQ_Flag = 0;
		}
	}

}
