/* Framebuffer sizes */
#define WIDTH 80
#define HEIGHT 25

/* The C function */
int sum_of_three(int arg1, int arg2, int arg3)
{
    return arg1 + arg2 + arg3;
}

/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    char *fb = (char *) 0x000B8000;
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

void write_test()
{
    #define FB_GREEN     2
    #define FB_DARK_GREY 8

    fb_write_cell(0, 'A', FB_GREEN, FB_DARK_GREY);   
}

/* kernel entry */
void kmain()
{
    int i;

    #define FB_GREEN     2
    #define FB_DARK_GREY 8

    for (i = 0; i < (2*WIDTH*HEIGHT); i+=2)
    {
        fb_write_cell(i, '\0' + i, FB_GREEN, FB_DARK_GREY);
    }
}
