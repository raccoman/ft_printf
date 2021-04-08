#include "../include/handler.h"

void	ft_calculate2(double value, double *mantissa, int *exponent)
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
		while (ABS((INT128)*mantissa) / 10.0 == 0)
		{
			*mantissa *= 10.0;
			*exponent -= 1;
		}
	}
}

void	ft_prepare_float(t_format *format, double value, int exponent)
{
	INT128	fpart;
	INT128	ipart;

	if (value - (INT128)value == 0 && !format->flags[SHARP])
		format->precision.value = 0;
	else if (value != 0)
		format->precision.value -= exponent + 1;
	if (format->flags[SHARP] || format->precision.value == 0)
		return ;
	if (ft_round((UINT128)value, value, format->precision.value))
		value += (double)(5.0 / ft_power(10, format->precision.value + 1));
	ipart = (INT128)value;
	fpart = ft_power(10, format->precision.value);
	fpart += (value - ipart) * ft_power(10, format->precision.value);
	while (fpart % 10 == 0)
	{
		format->precision.value--;
		fpart = ft_power(10, format->precision.value);
		fpart += (value - ipart) * ft_power(10, format->precision.value);
	}
}

void	ft_prepare_scientific(t_format *format, double mantissa)
{
	INT128	fpart;

	format->precision.value -= 1;
	fpart = ft_power(10, format->precision.value);
	fpart += mantissa * ft_power(10, format->precision.value);
	while (fpart % 10 == 0)
	{
		format->precision.value--;
		fpart = ft_power(10, format->precision.value);
		fpart += mantissa * ft_power(10, format->precision.value);
	}
}

void	ft_set_precision(t_format *format)
{
	if (!format->precision.present)
	{
		format->precision.present = TRUE;
		format->precision.value = 6;
	}
	else if (format->precision.value <= 0)
		format->precision.value = 1;
}

void	ft_handle_gravity(int *count, t_format format, va_list args, int upcase)
{
	double	mantissa;
	int		exponent;
	double	value;

	value = va_arg(args, double);
	ft_set_precision(&format);
	if (NAN_INF(value))
	{
		ft_print_float(count, format, value, upcase);
		return ;
	}
	ft_calculate2(value, &mantissa, &exponent);
	if (P_VALUE > exponent && exponent >= -4)
	{
		ft_prepare_float(&format, value, exponent);
		ft_print_float(count, format, value, upcase);
		return ;
	}
	ft_prepare_scientific(&format, mantissa);
	ft_print_scientific(count, format, value, upcase);
}
