// macros and functions for color manipulation
#define RGBA8(r, g, b, a) (((r) & 0xFF) | (((g) & 0xFF) << 8) | (((b) & 0xFF) << 16) | (((a) & 0xFF) << 24))
