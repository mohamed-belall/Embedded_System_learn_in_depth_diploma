Reset
		mov		R0 , #5
		bl		main
		
		
main
		mov		r2 , #0x100
		str		r0 , [r2]
		ldr		r3 , [r2]
		strb		r0 , [r2 , #0x1]
		
