/*
 ==============================================================================
 * @author         : mohamed belal
 * @file           : linker_script.ld for unit 3 lesson 3 lab 2 
 ==============================================================================
 */


MEMORY
{
	flash(RX)	: ORIGIN = 0x00000000 , LENGTH = 512M
	sram(RWX)	: ORIGIN = 0x20000000 , LENGTH = 512M
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
		
	} > sram
}
