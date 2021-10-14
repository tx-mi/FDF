#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*to;
	unsigned char		*from;
	unsigned char		symbol;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	symbol = (unsigned char)c;
	while (n--)
	{
		*(to++) = *(from++);
		if (*(from - 1) == symbol)
			return (to);
	}
	return (NULL);
}
