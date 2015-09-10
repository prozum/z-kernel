; Constants used for creating a multiboot header
MBALIGN		equ	1<<0		; Align loader modules on page boundries
MEMINFO		equ	1<<1		; Provide memory map
FLAGS		equ	MBALIGN | MEMINFO	; Multiboot 'flag' field
MAGIC		equ	0x1BADB002	; Some sort of sorcery
CHECKSUM	equ	-(MAGIC + FLAGS); Checksum to prove multiboot

; Multiboot header
section .multiboot
align 4
	dd	MAGIC
	dd	FLAGS
	dd	CHECKSUM

; Stack
section .multiboot_stack, nobits
align 4
stack_bottom:
resb 16384		; 16 KiB
stack_top:

; Kernel entry point
section .text
global _start
_start:
	mov esp, stack_top		; Prepare stack

	extern kernel_entry_early	; Early kernel entry for constructor
	call kernel_entry_early
	extern _init
	call _init

	extern kernel_entry_main	; Start the kernel and enter main
	call kernel_entry_main
	cli

.hang:
	hlt
	jmp .hang
