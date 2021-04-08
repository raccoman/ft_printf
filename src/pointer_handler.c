#include "handler.h"

void	ft_handle_pointer(int *count, t_format format, va_list arguments)
{
	size_t	pointer;
	char	*result;
	size_t	length;

	pointer = va_arg(arguments, size_t);
	result = ft_tohexa(pointer);
	length = ft_strlen(result);
	if (IS_WIDTH && !IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - length - 2);
	ft_write(count, "0x", 2);
	ft_write(count, result, length);
	if (IS_WIDTH && IS_MINUS)
		ft_write_width(count, IS_ZERO, W_VALUE - length - 2);
	free(result);
	result = NULL;
}
