
ENTRY(reset)

MEMORY
{
	Mem (rwx) :ORIGIN = 0x00000000 , LENGTH = 64M
}

SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}>Mem

	.text :
	{
		*(.text) *(.rodata)
	}>Mem

	.data :
	{
		*(.data)
	}>Mem

	.bss :
	{
		*(.bss)
	}>Mem

	. = . + 0x1000;   /*	1000 == 4KB of Stack Memory	*/
	stack_top = . ;
}