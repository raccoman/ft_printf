#include "../include/handler.h"

void	ft_print_scientific(int *c, t_format format, double v, int upcase)
{
	char	*s;
	size_t	l;

	s = ft_ftoe(v, IS_SHARP, IS_PRECISION ? P_VALUE : 6, upcase);
	l = ft_strlen(s);
	if (IS_WIDTH && !IS_MINUS && (!IS_ZERO || NAN_INF(v)))
		ft_write_width(c, FALSE, W_VALUE - l -
		(ft_isnegative(v) || IS_PLUS || IS_SPACE));
	if (ft_isnegative(v))
		ft_write(c, "-", 1);
	else if (IS_PLUS && v >= 0)
		ft_write(c, "+", 1);
	else if (IS_SPACE && v >= 0)
		ft_write(c, " ", 1);
	if (IS_WIDTH && !IS_MINUS && IS_ZERO && !NAN_INF(v))
		ft_write_width(c, TRUE, W_VALUE - l -
		(ft_isnegative(v) || IS_PLUS || IS_SPACE));
	ft_write(c, s, ft_strlen(s));
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(c, FALSE, W_VALUE - l -
		(ft_isnegative(v) || IS_PLUS || IS_SPACE));
	free(s);
}

void	ft_handle_scientific(int *c, t_format format, va_list args, int upcase)
{
	ft_print_scientific(c, format, va_arg(args, double), upcase);
}
