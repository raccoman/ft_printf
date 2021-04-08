#ifndef FORMAT_H
# define FORMAT_H

# include "utils.h"
# include <unistd.h>

typedef struct	s_int_value
{
	short		present;
	int			value;
}				t_int_value;

typedef enum	e_flag
{
	MINUS = 0,
	PLUS = 1,
	SPACE = 2,
	ZERO = 3,
	SHARP = 4
}				t_flag;

typedef enum	e_length
{
	NONE = -1,
	SHORT = 0,
	SHORT_SHORT = 1,
	LONG = 2,
	LONG_LONG = 3
}				t_length;

typedef enum	e_type
{
	PERCENT = '%',
	CHAR = 'c',
	STRING = 's',
	POINTER = 'p',
	DECIMAL = 'd',
	INTEGER = 'i',
	UNSIGNED = 'u',
	HEX_LOWCASE = 'x',
	HEX_UPCASE = 'X',
	NUMBERS = 'n',
	FLOAT_L = 'f',
	FLOAT_LL = 'F',
	G_LOWCASE = 'g',
	G_UPCASE = 'G',
	E_LOWCASE = 'e',
	E_UPCASE = 'E'
}				t_type;

typedef struct	s_format
{
	short		flags[5];
	t_int_value	width;
	t_int_value precision;
	t_length	length;
	t_type		type;
}				t_format;

void			ft_reset_format(t_format *format);
short			ft_is_type(int c);
short			ft_is_flag(int c);
short			ft_is_length(int c);

#endif
