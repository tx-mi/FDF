#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicate_str;
	char	*start;
	char	*temp;
	char	*str1;

	str1 = (char *)s1;
	temp = str1;
	while (*temp)
		temp++;
	duplicate_str = (char *)malloc(sizeof(char) * (temp - str1 + 1));
	if (!duplicate_str)
		return (NULL);
	start = duplicate_str;
	while (*str1)
		*duplicate_str++ = *str1++;
	*duplicate_str = '\0';
	return (start);
}
