#include "handler.h"

void	ft_part2(int *count, t_format format, __int128_t value, size_t width)
{
	if (IS_WIDTH && !IS_MINUS && (!IS_ZERO || IS_PRECISION))
		ft_write_width(count, FALSE, width);
	if (value < 0)
		ft_write(count, "-", 1);
	else if (IS_PLUS && value >= 0)
		ft_write(count, "+", 1);
	else if (IS_SPACE && value >= 0)
		ft_write(count, " ", 1);
	if (IS_WIDTH && !IS_MINUS && IS_ZERO && !IS_PRECISION)
		ft_write_width(count, TRUE, width);
}

void	ft_print_decimal(int *count, t_format format, INT128 value)
{
	char	*string;
	size_t	slength;
	int		precision;
	size_t	width;

	string = ft_itoa_base(ABS(value), 10, 0);
	slength = ft_strlen(string);
	width = 0;
	precision = IS_PRECISION && P_VALUE >= 0 ? P_VALUE - slength : 0;
	if (IS_PRECISION && P_VALUE == 0 && value == 0)
		slength = 0;
	if (IS_PRECISION && P_VALUE >= 0)
		precision = P_VALUE - slength;
	if (IS_WIDTH)
		width = W_VALUE - slength - (precision > 0 ? precision : 0) -
				(value < 0 || IS_PLUS || IS_SPACE);
	ft_part2(count, format, value, width);
	if (IS_PRECISION)
		while (precision-- > 0)
			ft_write(count, "0", 1);
	ft_write(count, string, slength);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, FALSE, width);
	free(string);
}

void	ft_handle_decimal(int *count, t_format format, va_list arguments)
{
	if (format.length == LONG_LONG)
		ft_print_decimal(count, format, va_arg(arguments, long long int));
	else if (format.length == LONG)
		ft_print_decimal(count, format, va_arg(arguments, long int));
	else if (format.length == SHORT)
		ft_print_decimal(count, format, (short int)va_arg(arguments, int));
	else if (format.length == SHORT_SHORT)
		ft_print_decimal(count, format, (signed char)va_arg(arguments, int));
	else
		ft_print_decimal(count, format, va_arg(arguments, int));
}
