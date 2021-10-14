#include "get_next_line.h"

size_t	ft_strlen(const char *str, char c)
{
	char	*copy_str;

	copy_str = (char *)str;
	while (*copy_str && *copy_str != c)
		copy_str++;
	return (copy_str - str);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	char	*start_str;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	j_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1));
	if (!j_str)
		return (NULL);
	start_str = j_str;
	while (*str1)
		*j_str++ = *str1++;
	while (*str2)
		*j_str++ = *str2++;
	*j_str = '\0';
	return (start_str);
}

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

int	is_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
