/*
 ==============================================================================
 * @author         : mohamed belal
 * @file           : startup.c  
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


extern unsigned int _stack_top;
unsigned int vectors[] __attribute__((section(".vectors"))) = {
	(unsigned int) & _stack_top,
	(unsigned int) & Rest_Handler,
	(unsigned int) & NMI_Handler,
	(unsigned int) & H_Fault_Handler,
	(unsigned int) & MM_Handler,
	(unsigned int) & Bus_Handler,
	(unsigned int) & Usage_Handler,
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
