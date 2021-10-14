#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (i < dstsize && dst[i])
		i++;
	while ((i + j) < (dstsize - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}
