#include "utils.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *s;

	s = b;
	while (n > 0)
		s[--n] = (unsigned char)c;
	return (s);
}
