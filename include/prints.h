#ifndef PRINTS_H
#define PRINTS_H

#include <stdarg.h>

// i guess use underscore to say "i'm basically making a wrapper around this"
void _print(const char *text);
void _printf(const char *format, ...);

#endif // PRINTS_H
