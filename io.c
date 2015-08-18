#include "io.h"

void outb(unsigned short port, unsigned char data)
{
    asm("outb %0, %1"
        : : "a" (data), "d" (port)
    );
}
