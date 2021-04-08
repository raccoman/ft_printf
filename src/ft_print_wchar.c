#include "utils.h"
#include "handler.h"
#include <wchar.h>

void	ft_print_wchar(int *count, wchar_t c, int lenght, char bytes[5])
{
	int i;

	i = 0;
	while (++i < lenght)
	{
		bytes[lenght - i] = 0x80 | (c & 0x3F);
		c >>= 6;
	}
	bytes[0] |= c;
	ft_write(count, bytes, lenght);
}

void	ft_prepare_wchar(int *count, wchar_t c)
{
	char	bytes[5];
	int		lenght;

	lenght = 0;
	if (c <= 0x7F)
	{
		bytes[0] = 0x00;
		lenght = 1;
	}
	else if (c <= 0x7FF)
	{
		bytes[0] = 0xC0;
		lenght = 2;
	}
	else if (c <= 0xFFFF)
	{
		bytes[0] = 0xE0;
		lenght = 3;
	}
	else if (c <= 0x10FFFF)
	{
		bytes[0] = 0xF0;
		lenght = 4;
	}
	ft_print_wchar(count, c, lenght, bytes);
}
