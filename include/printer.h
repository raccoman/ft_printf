#ifndef PRINTER_H
# define PRINTER_H

# include <unistd.h>
# include <stdlib.h>

void	ft_write_width(int *count, int zero, int length);

void	ft_write(int *count, const void *output, size_t bytes);

#endif
