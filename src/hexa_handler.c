#include "../include/handler.h"

void	ft_ww(int *count, t_format format, size_t width, int p)
{
	if (IS_WIDTH && !IS_MINUS && IS_ZERO && !IS_PRECISION)
		ft_write_width(count, TRUE, width);
	if (IS_PRECISION)
		while (p-- > 0)
			ft_write(count, "0", 1);
}

void	ft_p_hex(int *count, t_format format, INT128 v, int upcase)
{
	char	*string;
	size_t	l;
	int		p;
	size_t	width;

	string = ft_itoa_base(ABS(v), 16, upcase);
	l = ft_strlen(string);
	width = 0;
	p = 0;
	if (IS_PRECISION && P_VALUE == 0 && v == 0)
		l = 0;
	if (IS_PRECISION && P_VALUE >= 0)
		p = P_VALUE - l;
	if (IS_WIDTH)
		width = W_VALUE - l - (p > 0 ? p : 0) - (IS_SHARP && v != 0 ? 2 : 0);
	if (IS_WIDTH && !IS_MINUS && (!IS_ZERO || IS_PRECISION))
		ft_write_width(count, FALSE, width);
	if (IS_SHARP && v != 0)
		ft_write(count, upcase ? "0X" : "0x", 2);
	ft_ww(count, format, width, p);
	ft_write(count, string, l);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, FALSE, width);
	free(string);
}

void	ft_handle_hexadecimal(int *c, t_format format, va_list args, int uc)
{
	if (format.length == LONG_LONG)
		ft_p_hex(c, format, va_arg(args, unsigned long long int), uc);
	else if (format.length == LONG)
		ft_p_hex(c, format, va_arg(args, unsigned long int), uc);
	else if (format.length == SHORT)
		ft_p_hex(c, format, (unsigned short int)va_arg(args, unsigned int), uc);
	else if (format.length == SHORT_SHORT)
		ft_p_hex(c, format, (unsigned char)va_arg(args, unsigned int), uc);
	else
		ft_p_hex(c, format, va_arg(args, unsigned int), uc);
}
