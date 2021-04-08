#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *result;

	result = malloc(size * count);
	if (result)
		ft_memset(result, '\0', size * count);
	return (result);
}
