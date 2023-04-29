#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <stdio.h>

typedef struct
{
    char *data;
    size_t size;
} TextFile;

TextFile *textfile_open(const char *path);
void textfile_close(TextFile *file);
void textfile_pretty_print(TextFile *file);

#endif // TEXTFILE_H
