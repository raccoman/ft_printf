#include "utils.h"

long double	ft_power(long nb, int power)
{
	long double	result;

	result = 1.0;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	while (power < 0)
	{
		result /= nb;
		power++;
	}
	return (result);
}
