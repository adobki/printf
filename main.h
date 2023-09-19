#ifndef _PRINTF_H
#define _PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_str(char *str);

#endif /*_PRINTF_H*/
