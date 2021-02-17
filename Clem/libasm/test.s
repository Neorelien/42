global _ft_write

_ft_write:
		mov r8, rdx			;
		mov rax, 0x2000004  ;
	syscall					;
		jmp exit			;
exit:
	mov rax, r8				;
	ret						;
