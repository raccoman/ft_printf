#include <stdarg.h>
#include <stdio.h>
#include "../include/printer.h"
#include "ft_printf.h"

int		ft_printf(const char *string, ...)
{
	char		*input;
	int			count;
	va_list		arguments;
	t_format	format;
	char		c;

	count = 0;
	input = (char *)string;
	va_start(arguments, string);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (!ft_parse_format(arguments, &format, &input))
				return (-1);
			ft_handle(&count, format, arguments);
			continue;
		}
		c = *input;
		ft_write(&count, &c, 1);
		input++;
	}
	va_end(arguments);
	return (count);
}
