#include "format.h"
#include "ft_printf.h"

void			ft_reset_format(t_format *format)
{
	format->flags[0] = FALSE;
	format->flags[1] = FALSE;
	format->flags[2] = FALSE;
	format->flags[3] = FALSE;
	format->flags[4] = FALSE;
	format->width.present = FALSE;
	format->precision.present = FALSE;
	format->length = NONE;
	format->type = -1;
}

short			ft_is_type(int c)
{
	return (c == PERCENT || c == CHAR || c == STRING || c == POINTER
			|| c == DECIMAL || c == INTEGER || c == UNSIGNED
			|| c == HEX_LOWCASE || c == HEX_UPCASE || c == NUMBERS
			|| c == FLOAT_L || c == FLOAT_LL
			|| c == G_LOWCASE || c == G_UPCASE
			|| c == E_LOWCASE || c == E_UPCASE);
}

short			ft_is_flag(int c)
{
	return (c == '-' || c == '+' || c == ' '
			|| c == '0' || c == '#');
}

short			ft_is_length(int c)
{
	return (c == 'h' || c == 'l');
}
