void _print(const char *text)
{
    printf("%s", text);
}

// the easy one. just use the normal stdlib function.
void _printf(const char *format, ...)
{
    printf(format, ...);
}