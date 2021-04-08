#include "handler.h"

void	ft_handle(int *count, t_format format, va_list args)
{
	if (format.type == PERCENT)
		ft_handle_percent(count, format);
	else if (format.type == CHAR)
		ft_handle_char(count, format, args);
	else if (format.type == STRING)
		ft_handle_string(count, format, args);
	else if (format.type == POINTER)
		ft_handle_pointer(count, format, args);
	else if (format.type == DECIMAL || format.type == INTEGER)
		ft_handle_decimal(count, format, args);
	else if (format.type == UNSIGNED)
		ft_handle_unsigned(count, format, args);
	else if (format.type == FLOAT_L || format.type == FLOAT_LL)
		handle_float(count, format, args, format.type == FLOAT_LL);
	else if (format.type == HEX_LOWCASE || format.type == HEX_UPCASE)
		ft_handle_hexadecimal(count, format, args, format.type == HEX_UPCASE);
	else if (format.type == NUMBERS)
		ft_handle_numbers(count, format, args);
	else if (format.type == E_LOWCASE || format.type == E_UPCASE)
		ft_handle_scientific(count, format, args, format.type == E_UPCASE);
	else if (format.type == G_LOWCASE || format.type == G_UPCASE)
		ft_handle_gravity(count, format, args, format.type == E_UPCASE);
}
