#include "utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destination;
	const unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	i = 0;
	destination = dst;
	source = src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
