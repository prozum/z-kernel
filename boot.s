; Constants used for creating a multiboot header
.set ALIGN,		1<<0		; Align loader modules on page boundries
.set MEMINFO,		1<<1		; Provide memory map
.set FLAGS,		ALIGN | MEMINFO	; Multiboot 'flag' field
.set MAGIC,		0x1BADB002	; Some sort of sorcery
.set CHECKSUM,		-(MAGIC + FLAGS); Checksum to prove multiboot

; Multiboot header
.section .multiboot
.align 4
.long magic
.long FLAGS
.long CHECKSUM

; Stack
.section .bootstrap, "aw", @nobits
stack_bottom:
.skip 16384		; 16 KiB
stack_top:

; Kernel entry point
.section .text
.global _start
.type _start, @function
_start:
	movl $stack_top, %esp
	call kernel_entry_main
	cli
	hlt

.Lhang
	jmp .Lhang

.size _start . - _start
