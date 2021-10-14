#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*to;
	unsigned const char	*from;

	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	while (n--)
		*(to++) = *(from++);
	return (dst);
}
