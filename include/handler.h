#ifndef HANDLER_H
# define HANDLER_H

# include "utils.h"
# include "format.h"
# include "printer.h"
# include <stdarg.h>

void	ft_handle(int *count, t_format format, va_list args);

void	ft_handle_percent(int *count, t_format format);

void	ft_handle_char(int *count, t_format format, va_list arguments);

void	ft_handle_string(int *count, t_format format, va_list arguments);

void	ft_handle_pointer(int *count, t_format format, va_list arguments);

void	ft_handle_decimal(int *count, t_format format, va_list arguments);

void	ft_handle_unsigned(int *c, t_format format, va_list args);

void	handle_float(int *count, t_format format, va_list args, int upcase);

void	ft_handle_hexadecimal(int *c, t_format format, va_list args, int uc);

void	ft_handle_numbers(int *count, t_format format, va_list arguments);

void	ft_handle_scientific(int *c, t_format format, va_list args, int upcase);

void	ft_handle_gravity(int *count, t_format format,
		va_list args, int upcase);

void	ft_print_float(int *count, t_format format, double value, int upcase);

void	ft_print_scientific(int *c, t_format format, double v, int upcase);

#endif
