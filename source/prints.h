#define INFO(str) printf("INFO: \x1b[0;0H%s", str);
#define ERROR(str) printf("ERROR: \x1b[%d;%dH%s", 30, 10, str);
