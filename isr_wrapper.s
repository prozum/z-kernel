.globl isr_wrapper
.align 4

isr_wrapper:
	pushal
	cld
	call interrupt_handler
	popal
	iret
