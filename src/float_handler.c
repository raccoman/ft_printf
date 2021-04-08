#include "handler.h"

void	ft_print_fflags(t_format format, double value, int *count, size_t width)
{
	if (IS_WIDTH && !IS_MINUS && IS_ZERO &&
				(ft_isnan(value) || ft_isinf(value)))
		ft_write_width(count, FALSE, width);
	if (ft_isnegative(value))
		ft_write(count, "-", 1);
	else if (IS_PLUS && value >= 0)
		ft_write(count, "+", 1);
	else if (IS_SPACE && value >= 0)
		ft_write(count, " ", 1);
	if (IS_WIDTH && !IS_MINUS && IS_ZERO &&
				!ft_isnan(value) && !ft_isinf(value))
		ft_write_width(count, TRUE, width);
}

void	ft_pp(int *count, t_format format, size_t width)
{
	if (IS_SHARP && P_VALUE == 0)
		ft_write(count, ".", 1);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, FALSE, width - (IS_SHARP && P_VALUE == 0));
}

void	ft_print_float(int *count, t_format format, double value, int upcase)
{
	char	*string;
	size_t	slength;
	int		precision;
	size_t	width;

	string = ft_ftoa(value, !IS_PRECISION ||
						P_VALUE < 0 ? 6 : P_VALUE, upcase);
	slength = ft_strlen(string);
	width = 0;
	precision = 0;
	if (IS_PRECISION && P_VALUE >= 0 && !ft_isnan(value) && !ft_isinf(value))
		precision = P_VALUE - slength;
	if (IS_WIDTH)
		width = W_VALUE - slength - (precision > 0 ? precision : 0) -
				(ft_isnegative(value) || IS_PLUS || IS_SPACE ? 1 : 0);
	if (IS_WIDTH && !IS_MINUS && !IS_ZERO)
		ft_write_width(count, FALSE, width);
	ft_print_fflags(format, value, count, width);
	ft_write(count, string, slength);
	if (IS_PRECISION)
		while (precision-- > 0)
			ft_write(count, "0", 1);
	ft_pp(count, format, width);
	free(string);
}

void	handle_float(int *count, t_format format, va_list args, int upcase)
{
	ft_print_float(count, format, va_arg(args, double), upcase);
}
