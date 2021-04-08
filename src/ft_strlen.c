#include "utils.h"

size_t	ft_strlen(const char *string)
{
	size_t i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

size_t	ft_strclen(const char *string, int c)
{
	size_t i;

	i = 0;
	while (string[i] && string[i] != c)
		i++;
	return (i);
}

size_t	ft_wstrlen(const wchar_t *string)
{
	size_t i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
