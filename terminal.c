#include <stdint.h>
#include <stddef.h>

#include "vga.h"
#include "terminal.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

size_t strlen(const char* str)
{
	size_t len = 0;
	while(str[len] != 0)
	{
		len++;
	}
	return len;
}

void terminal_initialize()
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for(size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color)
{
	terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_scroll()
{
	for(size_t y = 1; y < VGA_HEIGHT; y++)
	{
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t index_new = (y - 1) * VGA_WIDTH + x;
			const size_t index_current = y * VGA_WIDTH + x;
			terminal_buffer[index_new] = terminal_buffer[index_current];
		}
	} 
	const size_t index_helper = 24 * VGA_WIDTH;
	for(size_t x = 0; x < VGA_WIDTH; x++)
	{
		terminal_buffer[index_helper + x] = make_vgaentry(' ', terminal_color);
	}
}

void terminal_putchar(char c)
{
	if(c == '\n')
	{
		if(terminal_row + 1 == VGA_HEIGHT)
		{
			terminal_scroll();
			terminal_row = 24;
		}
		else
		{
			terminal_row++;
		}
		terminal_column = 0;	
	}
	else
	{	
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if(++terminal_column == VGA_WIDTH)
		{
			terminal_column = 0;
			if(++terminal_row == VGA_HEIGHT)
			{
				terminal_scroll();
				terminal_row = 24;
			}
		}
	}
}

void terminal_writestring(const char* data)
{
	size_t datalen = strlen(data);
	for(size_t i = 0; i < datalen; i++)
	{
		terminal_putchar(data[i]);
	}
}
