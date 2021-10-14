#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_ptr;

	temp_ptr = (unsigned char *)b;
	while (len--)
		*(temp_ptr++) = (unsigned char)c;
	return (b);
}
