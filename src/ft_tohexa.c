#include "utils.h"

static char	*set_base(UINT128 nb, int upcase)
{
	char	*out;
	size_t	count;

	if (nb < 2)
		return (0x0);
	out = (char *)ft_calloc(nb + 1, sizeof(char));
	if (!out)
		return (NULL);
	count = 0;
	while (count < (size_t)nb)
	{
		out[count] = (char)('0' + count);
		if (count > 9)
			out[count] = (char)((upcase ? 'A' : 'a') + (count - 10));
		count++;
	}
	out[count] = 0;
	return (out);
}

static char	*digits_to_b(UINT128 *dig, UINT128 size, const char *base)
{
	char	*out;

	if (!(out = (char *)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	while (size > (size_t)0)
	{
		out[size - 1] = base[*dig];
		dig++;
		size--;
	}
	return (out);
}

char		*ft_itoa_base(UINT128 nb, int base_num, int upcase)
{
	UINT128		dig[64];
	char		*base;
	UINT128		it;
	char		*out;

	base = set_base(base_num, upcase);
	if (!base)
		return (NULL);
	it = 0;
	if (nb == 0)
	{
		it = 1;
		dig[0] = 0;
	}
	while (nb != 0)
	{
		dig[it] = nb % base_num;
		nb = (nb - dig[it]) / base_num;
		it++;
	}
	out = digits_to_b(dig, it, base);
	free(base);
	return (out);
}

char		*ft_tohexa(UINT128 n)
{
	return (ft_itoa_base(n, 16, 0));
}
