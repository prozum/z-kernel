/* Framebuffer sizes */
#define WIDTH 80
#define HEIGHT 25

typedef enum
{
    FB_BLACK,
    FB_BLUE,
    FB_GREEN,
    FB_CYAN,
    FB_RED,
    FB_MAGENTA,
    FB_BROWN,
    FB_LIGHT_GREY,
    FB_DARK_GREY,
    FB_LIGHT_BLUE,
    FB_LIGHT_GREEN,
    FB_LIGHT_CYAN,
    FB_LIGHT_RED,
    FB_LIGHT_MAGENTA,
    FB_LIGHT_BROWN,
    FB_WHITE
} fb_color_t;

void fb_write_cell (unsigned int i, char c, fb_color_t fg, fb_color_t bg);

void write_test();

