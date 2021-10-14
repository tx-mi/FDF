#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = (char *)s;
	if (c == '\0')
		return (str + len);
	while (len--)
	{
		if (*(str + len) == (char)c)
			return (str + len);
	}	
	return (0);
}
