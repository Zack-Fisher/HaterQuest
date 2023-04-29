#include "prints.h"
// platform nonspecific printing functions.

#ifdef _3DS
    #include <3ds.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Unsupported platform"
#endif

void print(const char *text, int x, int y) {
    #ifdef _3DS
        printf("\x1b[%d;%dH%s", y, x, text);
    #elif defined(__linux__)
        mvprintw(y, x, "%s", text);
    #endif
}

void fprint(int x, int y, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    
    print(buffer, x, y);
    
    va_end(args);
}
