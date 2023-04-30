#include "text.h"
#include "../prints.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_HEADER "romfs/text/%s"

TextFile *textfile_open(const char *filename)
{
    char path[256];
    snprintf(path, sizeof(path), TEXT_HEADER, filename);

    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileSize + 1);
    if (buffer == NULL)
    {
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0';
    fclose(file);

    TextFile *textFile = (TextFile *)malloc(sizeof(TextFile));
    if (textFile == NULL)
    {
        free(buffer);
        return NULL;
    }

    textFile->data = buffer;
    textFile->size = fileSize;

    return textFile;
}

void textfile_close(TextFile *file)
{
    if (file)
    {
        free(file->data);
        free(file);
    }
}

void textfile_pretty_print(TextFile *file)
{
    if (file && file->data)
    {
        _printf(0, 0, "-----READING FILE <%s>-----\n", file->name);
        _printf(0, 1, "%s\n", file->data);
    }
}
