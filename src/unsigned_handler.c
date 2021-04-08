#include "handler.h"

void	ft_wp(int *count, t_format format, int precision)
{
	if (IS_PRECISION)
		while (precision-- > 0)
			ft_write(count, "0", 1);
}

void	ft_h_uint(int *count, t_format format, UINT128 value)
{
	char	*string;
	size_t	slength;
	int		precision;
	size_t	width;

	string = ft_itoa_base(ABS(value), 10, 0);
	slength = ft_strlen(string);
	width = 0;
	precision = 0;
	if (IS_PRECISION && P_VALUE == 0 && value == 0)
		slength = 0;
	if (IS_PRECISION && P_VALUE >= 0)
		precision = P_VALUE - slength;
	if (IS_WIDTH)
		width = W_VALUE - slength - (precision > 0 ? precision : 0);
	if (IS_WIDTH && !IS_MINUS && (!IS_ZERO || IS_PRECISION))
		ft_write_width(count, FALSE, width);
	if (IS_WIDTH && !IS_MINUS && IS_ZERO && !IS_PRECISION)
		ft_write_width(count, TRUE, width);
	ft_wp(count, format, precision);
	ft_write(count, string, slength);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, FALSE, width);
	free(string);
}

void	ft_handle_unsigned(int *c, t_format format, va_list args)
{
	if (format.length == LONG_LONG)
		ft_h_uint(c, format, va_arg(args, unsigned long long int));
	else if (format.length == LONG)
		ft_h_uint(c, format, va_arg(args, unsigned long int));
	else if (format.length == SHORT)
		ft_h_uint(c, format, (unsigned short int)va_arg(args, unsigned int));
	else if (format.length == SHORT_SHORT)
		ft_h_uint(c, format, (unsigned char)va_arg(args, unsigned int));
	else
		ft_h_uint(c, format, va_arg(args, unsigned int));
}
