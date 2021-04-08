#include "utils.h"

int		ft_isinf(double x)
{
	return (!ft_isnan(x) && ft_isnan(x - x));
}
