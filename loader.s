global loader                   ; the entry symbol for ELF

MAGIC_NUMBER equ 0x1BADB002     ; define the magic number constant
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; calculate the checksum
                                ; (magic number + checksum + flags should equal 0)

section .text:                  ; start of the text (code) section
align 4                         ; the code must be 4 byte aligned
    dd MAGIC_NUMBER             ; write the magic number to the machine code,
    dd FLAGS                    ; the flags,
    dd CHECKSUM                 ; and the checksum


section .bootstrap_stack, nobits; start of the stack section
align 4				; code must be 4 byte aligned
stack_bottom:			; bottom of the stack
resb 16384			; allocated stack size (16 KiB)
stack_top:			; stack top

section .text
loader:                         ; the loader label (defined as entry point in linker script)
    
	mov esp, stack_top	; prepared the stack
	extern kmain
	call kmain		; starts the kernel

	cli
.loop:
	hlt
    jmp .loop                   ; loop forever

