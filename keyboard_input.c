/*
* Part of this file uses code made by:
* Copyright (C) 2014  Arjun Sreedharan
* License: GPL version 2 or higher http://www.gnu.org/licenses/gpl.html
*/

#include "keymap.h"
#include "vga.h"
#include "terminal.h"

#define keyboard_data_port 0x60
#define keyboard_status_port 0x64
#define idt_size 256
#define interrupt_gate 0x8e
#define kernel_code_segment_offset 0x08

#define enter_key_code 0x1c

extern uint8_t keyboard_map[128];
extern void keyboard_handler(void);
extern char read_port(uint16_t port);
extern void write_port(uint16_t, uint8_t data);
extern void load_idt(uint32_t *idt_ptr);

typedef struct
{
	uint16_t offset_lowerbits;
	uint16_t selector;
	uint8_t zero;
	uint8_t type_attr;
	uint16_t offset_higherbits;
} IDT_entry;

IDT_entry IDT[idt_size];

void idt_initialize(void)
{
	uint32_t keyboard_address;
	uint32_t idt_address;
	uint32_t idt_ptr[2];

	keyboard_address = (uint32_t) keyboard_handler;
	IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
	IDT[0x21].selector = kernel_code_segment_offset;
	IDT[0x21].zero = 0;
	IDT[0x21].type_attr = interrupt_gate;
	IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;
	
	write_port(0x20, 0x11);
	write_port(0xA0, 0x11);

	write_port(0x21, 0x20);
	write_port(0xA1, 0x28);
	
	write_port(0x21, 0x00);
	write_port(0xA1, 0x00);

	write_port(0x21, 0x01);
	write_port(0xA1, 0x01);

	write_port(0x21, 0xff);
	write_port(0x21, 0xff);

	idt_address = (uint32_t) IDT;
	idt_ptr[0] = (sizeof (IDT_entry) * idt_size) + ((idt_address & 0xffff) << 16);
	idt_ptr[1] = idt_address >> 16;
	
	load_idt(idt_ptr);
}

void kb_initialize(void)
{
	write_port(0x21, 0xFD);
}

void keyboard_handler_main(void)
{
	uint8_t status;
	char keycode;

	write_port(0x20, 0x20);

	status = read_port(keyboard_status_port);
	if(status & 0x01)
	{
		keycode = read_port(keyboard_data_port);
		if(keycode < 0)
		{
			return;
		}
		if(keycode == enter_key_code)
		{
			terminal_putchar('\n');
			return;
		}

		 terminal_putchar((unsigned char) keymap[(uint8_t) keycode]);	
	}
}
