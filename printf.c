#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Prints all of the arguments when specified
 * @format: specifies the necessary operations
 * Return: void
 */

int _printf(const char *format, ...)
{
	int counter;
	int i;
	char *str;
	va_list a_list;

	counter = 0;
	va_start(a_list, format);
	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(a_list, int));
				break;
			case 's':
				str = va_arg(a_list, char*);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
			default:
				break;
		}
		if (format[i + 1] != '\0')
			printf(", ");
		i++;
		counter = i;
	}
	printf("\n");
	va_end(a_list);
	return counter;
}
