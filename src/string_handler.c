#include "handler.h"
#include "utils.h"
#include <wchar.h>

void	ft_handle_null(int *count, t_format format)
{
	size_t length;

	length = 6;
	if (IS_PRECISION && P_VALUE >= 0)
		length = MIN(P_VALUE, length);
	if (IS_WIDTH && !IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - length);
	ft_write(count, "(null)", length);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - length);
}

void	ft_handle_nstring(int *count, t_format format, char *string)
{
	size_t length;

	if (string == NULL)
	{
		ft_handle_null(count, format);
		return ;
	}
	length = ft_strlen(string);
	if (IS_PRECISION && P_VALUE >= 0)
		length = MIN(P_VALUE, length);
	if (IS_WIDTH && !IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - length);
	ft_write(count, string, length);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - length);
}

void	ft_handle_wstring(int *count, t_format format, const wchar_t *string)
{
	int i;
	int	length;

	if (string == NULL)
	{
		ft_handle_null(count, format);
		return ;
	}
	i = 0;
	length = ft_wstrlen(string);
	if (IS_PRECISION && P_VALUE >= 0)
		length = MIN(P_VALUE, length);
	if (IS_WIDTH && !IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - length);
	while (i < length)
		ft_prepare_wchar(count, string[i++]);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - length);
}

void	ft_handle_string(int *count, t_format format, va_list arguments)
{
	if (format.length == LONG)
		ft_handle_wstring(count, format, va_arg(arguments, const wchar_t *));
	else
		ft_handle_nstring(count, format, va_arg(arguments, char *));
}
