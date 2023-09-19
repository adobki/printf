#include "main.h"

/**
 * print_char - Prints a single character.
 *
 * @c: String to be printed.
 *
 * Return: 0 or 1 on SUCCESS,
 *        -1 on ERROR.
 */
int print_char(char c)
{
	int ret = 0;
	char *str;

	if (c)
		ret = write(STDOUT_FILENO, &c, 1);
	else
	{
		str = "(null)";
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		ret = 6;
	}

	return (ret);
}

/**
 * print_str - Prints a string without formatting.
 *
 * @str: String to be printed.
 *
 * Return: Number of characters printed.
 */
int print_str(char *str)
{
	int i = 0;

	if (!str || !*str)
		i = print_char(0);
	else
		while (*str)
			print_char(*str++), i++;

	return (i);
}

/**
 * _printf - Program entry point.
 *
 * @format: Format string used for printing.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list vargp;
	int i = 0, printed = 0;

	if (!format || !*format)
		return (printed);

	va_start(vargp, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
			{
				if (format[i] == '%')
					print_char('%'), printed++;
				if (format[i] == 'c')
					print_char(va_arg(vargp, int)), printed++;
				if (format[i] == 's')
					printed += print_str((char *)va_arg(vargp, char *));
			}
		}
		else
			print_char(format[i]), printed++;

		i++;
	}
	va_end(vargp);

	return (printed);
}
