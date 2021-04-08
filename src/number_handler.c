#include "../include/handler.h"

void	ft_handle_numbers(int *count, t_format format, va_list arguments)
{
	if (format.length == LONG_LONG)
		*va_arg(arguments, long long int *) = *count;
	else if (format.length == LONG)
		*va_arg(arguments, long int *) = *count;
	else if (format.length == SHORT_SHORT)
		*va_arg(arguments, signed char *) = *count;
	else if (format.length == SHORT)
		*va_arg(arguments, short int *) = *count;
	else
		*va_arg(arguments, int *) = *count;
}
