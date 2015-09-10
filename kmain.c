#include "terminal.h"
#include "io.h"

/* Global constructor */
void kernel_entry_early()
{
	terminal_initialize();
}

/* Draw Prozum logo */
void kernel_draw_prozum_logo(void)
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

/* kernel entry main */
void kernel_entry_main()
{
	kernel_draw_prozum_logo();
}
