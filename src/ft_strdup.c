#include "utils.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1);
	copy = (char *)ft_calloc(sizeof(char), len + 1);
	if (copy)
		ft_memcpy(copy, s1, len);
	return (copy);
}

char	*ft_strndup(const char *s1, size_t length)
{
	char	*copy;

	copy = (char *)ft_calloc(sizeof(char), MIN(ft_strlen(s1), length) + 1);
	if (copy)
		ft_memcpy(copy, s1, MIN(ft_strlen(s1), length));
	return (copy);
}
