#include "printer.h"

void	ft_write_width(int *count, int zero, int length)
{
	while (length-- > 0)
		ft_write(count, zero ? "0" : " ", 1);
}

void	ft_write(int *count, const void *output, size_t bytes)
{
	*count += bytes;
	write(1, output, bytes);
}
