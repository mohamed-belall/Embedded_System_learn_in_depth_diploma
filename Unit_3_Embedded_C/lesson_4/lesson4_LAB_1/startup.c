/*
 ==============================================================================
 * @author         : mohamed belal
 * @file           : startup.c for unit 3 lesson 3 lab 2 
 ==============================================================================
 */
extern int main(void);

void Default_Handler()
{
	Rest_Handler();
}
void Rest_Handler(void); 
void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));;
void MM_Handler(void) __attribute__((weak,alias("Default_Handler")));;
void Bus_Handler(void) __attribute__((weak,alias("Default_Handler")));;
void Usage_Handler(void) __attribute__((weak,alias("Default_Handler")));;

// booking 1024 B located at .bss through unintialized array of int 256 element [ 256*4byte = 1024 ] 
static unsigned long Stack_top[256];

 void  (* const g_p_fn_Vectors[])() __attribute__((section(".vectors")))=
 {
 	(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
 	& Rest_Handler,
	& NMI_Handler,
	& H_Fault_Handler,
	& MM_Handler,
	& Bus_Handler,
	& Usage_Handler,

 };

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
void Rest_Handler(void)
{
	// copy data section from flash to sram 
	unsigned int DATA_Size = (unsigned char*)&_E_data - (unsigned char*)_S_data;
	unsigned char*  P_src	 = (unsigned char*)&_E_text;
	unsigned char*  P_dst	 = (unsigned char*)&_S_data;
	for(int i=0; i<DATA_Size;i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}

	// int .bss section in sram ==> 0
	unsigned int Bss_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss;
	for(int i=0;i<Bss_Size;i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	} 
	
	// jumb main()
	main();
}
