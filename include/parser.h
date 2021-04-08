#ifndef PARSER_H
# define PARSER_H

# include "format.h"
# include <stdarg.h>

int		ft_parse_format(va_list arguments, t_format *format, char **input);

#endif
