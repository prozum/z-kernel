section .init
	; gcc add crtend.o's .init here
	pop ebp
	ret

section .fini
	; gcc add crtend.o's .fini here
	pop ebp
	ret
