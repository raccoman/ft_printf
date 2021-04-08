#include "utils.h"

int	ft_isnegative(double value)
{
	unsigned short *pd;

	pd = (unsigned short *)&value;
	return ((pd[3] & 0x8000) != 0);
}
