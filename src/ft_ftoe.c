#include "../include/utils.h"

void	ft_calculate(double value, long double *mantissa, INT128 *exponent)
{
	*mantissa = ABS(value);
	*exponent = 0;
	if (ABS(*mantissa) >= 1)
	{
		while (ABS((INT128)*mantissa) / 10.0 >= 1)
		{
			*mantissa /= 10;
			*exponent += 1;
		}
	}
	else if (ABS(value) > 0.0)
	{
		while ((INT128)*mantissa / 10.0 == 0)
		{
			*mantissa *= 10.0;
			*exponent -= 1;
		}
	}
}

void	ft_free_string(char *m_string, char *e_string)
{
	free(m_string);
	free(e_string);
}

char	*ft_compose(long double m, INT128 exponent, int precision, int dot)
{
	char	*composed;
	char	*m_string;
	char	*e_string;
	size_t	length;

	m_string = ft_ftoa(m, precision, 0);
	e_string = ft_itoa_base(ABS(exponent), 10, 0);
	length = ft_strlen(m_string) + 2 + (-10 < exponent && exponent < 10)
						+ ft_strlen(e_string) + (dot && precision == 0);
	if (!(composed = ft_calloc(length + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(composed, m_string, ft_strlen(m_string));
	if (dot && precision == 0)
		ft_memset(composed + ft_strlen(m_string), '.', 1);
	ft_memset(composed + ft_strlen(m_string) + (dot && precision == 0), 'e', 1);
	ft_memset(composed + ft_strlen(m_string) + 1 +
					(dot && precision == 0), exponent < 0 ? '-' : '+', 1);
	if (ABS(exponent) < 10)
		ft_memset(composed + ft_strlen(m_string) + 2 +
							(dot && precision == 0), '0', 1);
	ft_memcpy(composed + ft_strlen(m_string) + 1 + 1 +
							(-10 < exponent && exponent < 10) +
				(dot && precision == 0), e_string, ft_strlen(e_string));
	ft_free_string(m_string, e_string);
	return (composed);
}

char	*ft_ftoe(double value, int sharp, int precision, int upcase)
{
	INT128		exponent;
	long double	mantissa;

	if (ft_isnan(value))
		return (ft_strdup(upcase ? "NAN" : "nan"));
	if (ft_isinf(value))
		return (ft_strdup(upcase ? "INF" : "inf"));
	ft_calculate(value, &mantissa, &exponent);
	return (ft_compose(mantissa, exponent, precision, sharp));
}
