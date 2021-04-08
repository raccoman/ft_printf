#include "parser.h"
#include "utils.h"

void	ft_parse_flags(t_format *format, char **input)
{
	while (ft_is_flag(**input))
	{
		if (**input == '-')
		{
			format->flags[MINUS] = TRUE;
			format->flags[ZERO] = FALSE;
		}
		else if (**input == '+')
			format->flags[PLUS] = TRUE;
		else if (**input == ' ')
			format->flags[SPACE] = TRUE;
		else if (**input == '0' && !format->flags[MINUS])
			format->flags[ZERO] = TRUE;
		else if (**input == '#')
			format->flags[SHARP] = TRUE;
		(*input)++;
	}
}

void	ft_parse_width(t_format *format, va_list arguments, char **input)
{
	if (ft_is_digit(**input))
	{
		format->width.present = TRUE;
		format->width.value = ft_uatoi(input);
	}
	else if (**input == '*')
	{
		format->width.present = TRUE;
		format->width.value = va_arg(arguments, int);
		(*input)++;
	}
	if (format->width.present && format->width.value < 0)
	{
		format->flags[MINUS] = TRUE;
		format->width.value = ABS(format->width.value);
	}
}

void	ft_parse_precision(t_format *format, va_list arguments, char **input)
{
	if (**input != '.')
		return ;
	(*input)++;
	format->precision.present = TRUE;
	if (ft_is_digit(**input))
		format->precision.value = ft_uatoi(input);
	else if (**input == '*')
	{
		format->precision.value = va_arg(arguments, int);
		(*input)++;
	}
	else
		format->precision.value = 0;
}

void	ft_parse_length(t_format *format, char **input)
{
	while (ft_is_length(**input))
	{
		if (**input == 'h' && format->length != LONG &&
							format->length != LONG_LONG)
		{
			if (format->length == SHORT)
				format->length = SHORT_SHORT;
			else if (format->length == NONE)
				format->length = SHORT;
		}
		else if (**input == 'l')
		{
			if (format->length == LONG)
				format->length = LONG_LONG;
			else if (format->length != LONG_LONG && format->length != LONG)
				format->length = LONG;
		}
		(*input)++;
	}
}

int		ft_parse_format(va_list arguments, t_format *format, char **input)
{
	ft_reset_format(format);
	ft_parse_flags(format, input);
	ft_parse_width(format, arguments, input);
	ft_parse_precision(format, arguments, input);
	ft_parse_length(format, input);
	if (!ft_is_type(**input))
		return (FALSE);
	format->type = (unsigned char)**input;
	(*input)++;
	return (TRUE);
}
