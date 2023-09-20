#ifndef _PRINTF_H
#define _PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_str(char *str);
char *intToStr(int num);

#endif /*_PRINTF_H*/
