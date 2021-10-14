#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*to;
	unsigned char	*from;

	if (dst == NULL && src == NULL && len != 0)
		return (NULL);
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (src < dst)
	{
		to += (len - 1);
		from += (len - 1);
		while (from && to && len--)
			*(to--) = *(from--);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
