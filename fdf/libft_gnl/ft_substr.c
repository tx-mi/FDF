#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_start;
	char	*str_end;
	char	*sub_str;
	char	*res_start;

	str_start = (char *)s;
	str_end = str_start;
	while (*str_end)
		str_end++;
	if (!s || len <= 0 || start >= (str_end - str_start))
		return (ft_strdup(""));
	if ((long)len > (str_end - str_start))
		len = (str_end - str_start);
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	res_start = sub_str;
	str_start += start;
	while (len-- && *str_start)
		*sub_str++ = *str_start++;
	*sub_str = '\0';
	return (res_start);
}
