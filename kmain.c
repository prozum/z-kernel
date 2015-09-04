#include "terminal.h"

/* TODO: kernel early entry */

/* kernel entry main */
void kernel_entry_main()
{
	terminal_initialize();
	terminal_writestring("Hello, kernel world!\n");
}
