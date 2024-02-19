Reset
			bl		main
			
			
main
			mov		R0 , #5
			bl		subtract
			b		termination
			
			
subtract
			sub		r0 , r0 , #1
			cmp		r0 , #0
			bne		subtract
			
			mov		pc , lr
			
			
termination
