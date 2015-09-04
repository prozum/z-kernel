#include <stdint.h>

#include "io.h"

/* Send 8 bit value on I/O location. */
void outb(uint16_t port, uint8_t val)
{
	asm volatile ("outb %0, %1"
	: : "a" (val), "Nd" (port)
	);
}

/* Send 16 bit value on I/O location. */
void outw(uint16_t port, uint16_t val)
{
	asm volatile ("outw %0, %1"
	: : "a" (val), "d" (port)
	);
}

/* Send 32 bit value on I/O location. */
void outl(uint16_t port, uint32_t val)
{
	asm volatile ("outl %0, %1"
	: : "a" (val), "d" (port)
	);
}

/* Recieves 8 bit value from I/O location. */
uint8_t inb(uint16_t port)
{
	uint8_t ret;
	asm volatile ("inb %1, %0"
	: "=a" (ret) : "Nd" (port)
	);
	return ret;
}

/* Recieves 16 bit value from I/O location. */
uint16_t inw(uint16_t port)
{
	uint16_t ret;
	asm volatile ("inw %1, %0"
	: "=a" (ret) : "d" (port)
	);
	return ret;
}

/* Recieves 32 bit value from I/O location. */
uint32_t inl(uint16_t port)
{
	uint32_t ret;
	asm volatile ("inl %1, %0"
	: "=a" (ret) : "d" (port)
	);
	return ret;
}

#define FB_COMMAND_PORT		0x3D4
#define FB_DATA_PORT		0x3D5
#define FB_HIGH_BYTE_COMMAND	14
#define FB_LOW_BYTE_COMMAND	15

void fb_move_cursor(unsigned short pos)
{
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, pos & 0x00FF);
}
