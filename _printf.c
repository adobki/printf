#include "main.h"

/**
 * _printf - Program entry point.
 *
 * @format: Format string used for printing.
 *
 * Return: Number of characters printed on SUCCESS,
 *         -1 on ERROR.
 */
int _printf(const char *format, ...)
{
	va_list vargp;
	int i = 0, printed = 0;
	char *tmp = NULL;

	if (!format)
		return (-1);
	if (!*format)
		return (0);
	va_start(vargp, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
			{
				if (format[i] == '%')
					print_char('%'), printed++, i++;
				else if (format[i] == 'c')
					print_char(va_arg(vargp, int)), printed++, i++;
				else if (format[i] == 's')
					printed += print_str((char *)va_arg(vargp, char *)), i++;
				else if (format[i] == 'd' || format[i] == 'i')
				{
					tmp = intToStr(va_arg(vargp, int));
					printed += print_str(tmp), i++;
					if (*tmp != '0')
						free(tmp);
				}
				else
					print_char('%'), printed++;
			}
			else
				return (-1);
		}
		else
			print_char(format[i]), printed++, i++;
	}
	va_end(vargp);
	return (printed);
}

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
	return (write(STDOUT_FILENO, &c, 1));
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

	if (!str)
	{
		str = "(null)";
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		write(STDOUT_FILENO, str++, 1);
		i = 6;
	}
	else
		while (*str)
			print_char(*str++), i++;

	return (i);
}

/**
 * intToStr - Converts an integer to a str.
 *
 * @num: Integer to be converted to a str.
 *
 * Return: Pointer to new string of integer on SUCCESS.
 *         NULL on ERROR.
 */
char *intToStr(int num)
{
	int len = 0, isSigned = 0, isMin = 0, tmp = num;
	char *str = NULL;

	if (!num)
		return ("0");

	if (num == INT_MIN)
		isSigned = 1, len++, num = tmp = INT_MAX, isMin = 1;
	else if (num < 0)
		isSigned = 1, len++, num = tmp *= -1;

	while (tmp >= 1)
		tmp = tmp / 10, len++;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	str[len--] = 0;
	while (num >= 1)
		str[len--] = (num % 10) + '0', num /= 10;

	if (isSigned)
		str[len] = '-';

	if (isMin)
	{
		len = 0;
		while (str[len])
			len++;
		str[len - 1] += 1;
	}

	return (str);
}
