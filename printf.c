#include "main.h"

/**
 * _printf - to print all types of inputs.
 * @format: string of all kinds of formating.
 * Return: number of all printed bytes.
*/
int _printf(const char *format, ...)
{
	const char *cpy;
	int count = 0;
	char buffer[20];
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (cpy = format; *cpy != '\0'; cpy++)
	{
		if (*cpy == '%' && *(cpy + 1) != '\0')
		{
			cpy++;
		switch (*cpy)
			{
				case 'c':
						count = count + newputchar(va_arg(args, int));
						break;
				case 's':
					{
						char *str = va_arg(args, char *);

						while (*str)
						{
							count = (count + newputchar(*str));
						str++;
						}
						if (str == NULL)
						{
							count = count + write(1, "(null)", 6);
						}
					}
						break;
				case '%':
						count = count + newputchar('%');
					break;
				case 'd':
				case 'i':
					{
						int number = va_arg(args, int);
						int n = snprintf(buffer, sizeof(buffer), "%d", number);
						count = count + write(1, buffer, n);
					break;
					}
				default:
					newputchar('%');
					newputchar(*cpy);
					count = count + 2;
						break;
		}
		}
		else
		{
			count = count + newputchar(*cpy);
		}
	}
	va_end(args);
	return (count);
}
