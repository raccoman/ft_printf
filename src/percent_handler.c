#include "handler.h"

void		ft_handle_percent(int *count, t_format format)
{
	if (IS_WIDTH && !IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - 1);
	ft_write(count, "%", 1);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - 1);
}
