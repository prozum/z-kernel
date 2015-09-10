; Used for global constructors, called before kernel code

section .init
global _init
_init:
	push ebp
	; mov esp, ebp
	mov ebp, esp
	; gcc add crtbegin.o's .init here

section .fini
global _fini
_fini:
	push ebp
	;mov esp, ebp
	mov ebp, esp
	; gcc add crtbegin.o's .fini here
