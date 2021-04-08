#include "utils.h"

int		ft_uatoi(char **input)
{
	int res;

	res = 0;
	while (ft_is_digit(**input))
	{
		res = res * 10 + **input - '0';
		(*input)++;
	}
	return (res);
}
