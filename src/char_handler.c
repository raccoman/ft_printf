#include "handler.h"
#include "utils.h"
#include <wchar.h>

void		ft_print_nchar(int *count, int c)
{
	ft_write(count, &c, 1);
}

void		ft_handle_char(int *count, t_format format, va_list arguments)
{
	if (IS_WIDTH && !IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - 1);
	if (format.length == LONG)
		ft_prepare_wchar(count, va_arg(arguments, wchar_t));
	else
		ft_print_nchar(count, va_arg(arguments, int));
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - 1);
}
