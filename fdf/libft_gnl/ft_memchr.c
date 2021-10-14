#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	symbol;

	src = (unsigned char *)s;
	symbol = c;
	while (n--)
	{
		if (symbol == *(src))
			return (src);
		src++;
	}
	return (NULL);
}
