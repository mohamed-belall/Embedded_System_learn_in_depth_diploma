/*
 ==============================================================================
 * @author         : mohamed belal
 * @file           : linker_script.ld for unit 3 lesson 3 lab 2 
 ==============================================================================
 */


MEMORY
{
	flash(RX)	: ORIGIN = 0x08000000 , LENGTH = 128K
	sram(RWX)	: ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata )
		_E_text = .;
	} > flash

	.data : {
		_S_data = .;
		*(.data*)
		. = ALIGN(4);
		_E_data = .;
	} >sram AT> flash

	.bss : {
		_S_bss = .;
		*(.bss*)
		_E_bss = .;
		. = ALIGN(4);
		. = . + 0x1000;
		_stack_top = .;
	} > sram
}
