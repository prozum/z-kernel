#include "terminal.h"
#include "io.h"

/* Global constructor */
void kernel_entry_early()
{
	terminal_initialize();
}

/* kernel entry main */
void kernel_entry_main()
{
	terminal_writestring("                    ###    #########################        \n");
	terminal_writestring("                    ###    #########################        \n");
	terminal_writestring("                    ###    #####                            \n");
	terminal_writestring("                    ###       #####                         \n");
	terminal_writestring("                    ###          #####                      \n");
	terminal_writestring("                    ###             #####                   \n");
	terminal_writestring("                    ###                #####                \n");
	terminal_writestring("              ###############             #####             \n");
	terminal_writestring("                    ###                #####                \n");
	terminal_writestring("                    ###             #####                   \n");
	terminal_writestring("                    ###          #####                      \n");
	terminal_writestring("                    ###       #####                         \n");
	terminal_writestring("                    ###    #####                            \n");
	terminal_writestring("                    ###    #########################        \n");
	terminal_writestring("                    ###    #########################        \n");
	terminal_writestring("                                                            \n");
	terminal_writestring("           #####       #   # ##### ###   ##  # ##### #      \n");
	terminal_writestring("               #       #  #  #     #  #  ##  # #     #      \n");
	terminal_writestring("              #        # #   #     #   # # # # #     #      \n");
	terminal_writestring("             #         ##    ####  #  #  # # # ####  #      \n");
	terminal_writestring("             #   ##### ##    #     ###   # # # #     #      \n");
	terminal_writestring("            #          # #   #     #  #  # # # #     #      \n");
	terminal_writestring("           #           #  #  #     #   # #  ## #     #      \n");
	terminal_writestring("           #####       #   # ##### #   # #  ## ##### #####  \n");
}
