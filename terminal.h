#ifndef _KERNEL_TERMINAL_H
#define _KERNEL_TERMINAL_H
#endif

#include <stddef.h>
#include <stdint.h>

size_t strlen(const char* str);
void terminal_initialize();
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_writestring(const char* data);
