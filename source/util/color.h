// macros and functions for color manipulation
#define RGBA(r, g, b, a) (((r) & 0xFF) | (((g) & 0xFF) << 8) | (((b) & 0xFF) << 16) | (((a) & 0xFF) << 24))

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u32 hex;
} Color;

static inline Color color_from_rgba(u8 r, u8 g, u8 b, u8 a)
{
    Color color { r, g, b, a, RGBA(r, g, b, a) };
    return color;
}

static inline Color color_from_rgb(u8 r, u8 g, u8 b)
{
    return color_from_rgba(r, g, b, 0xFF);
}

static inline Color color_from_hex(u32 hex)
{
    Color color;
    color.r = (hex >> 24) & 0xFF;
    color.g = (hex >> 16) & 0xFF;
    color.b = (hex >> 8) & 0xFF;
    color.a = hex & 0xFF;
    color.hex = hex;
    return color;
}
