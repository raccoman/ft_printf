#include "utils.h"

void	*ft_realloc(void *src, size_t length, size_t new_size)
{
	void	*output;

	if (!(output = malloc(new_size)))
		return (NULL);
	ft_memcpy(output, src, length);
	free(src);
	src = NULL;
	return (output);
}
