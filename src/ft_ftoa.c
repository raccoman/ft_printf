#include "utils.h"

int		ft_round(UINT128 part, double value, int precision)
{
	if (part % 2 != 0)
		return (value >= part + (5 / ft_power(10, precision + 1)));
	else
		return (value > part + (5 / ft_power(10, precision + 1)));
}

char	*ft_check(double value, int upcase)
{
	if (ft_isnan(value))
		return (ft_strdup(upcase ? "NAN" : "nan"));
	if (ft_isinf(value))
		return (ft_strdup(upcase ? "INF" : "inf"));
	return (NULL);
}

void	ft_add_preci(char *string, size_t i, long double value, int precision)
{
	precision += i;
	while ((int)i < precision)
	{
		value *= 10;
		string[i++] = (char)((int)value + 48);
		value -= (int)value;
	}
}

char	*ft_ftoa(long double value, int precision, int upcase)
{
	char	*string;
	char	*s_ipart;
	size_t	l_length;

	if ((string = ft_check(value, upcase)) != NULL)
		return (string);
	value = ABS(value);
	if (ft_round((UINT128)value, value, precision))
		value += 5.0 / ft_power(10, precision + 1);
	s_ipart = ft_itoa_base((INT128)value, 10, 0);
	l_length = ft_strlen(s_ipart);
	string = ft_calloc(l_length + 1 + precision + 1, sizeof(char));
	ft_memcpy(string, s_ipart, l_length);
	free(s_ipart);
	if (precision == 0)
		return (string);
	ft_memset(string + l_length, '.', 1);
	ft_add_preci(string, l_length + 1, value - (INT128)value, precision);
	return (string);
}
