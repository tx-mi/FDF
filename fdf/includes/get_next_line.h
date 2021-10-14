#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <fcntl.h>	// open() and O_XXX flags
# include <sys/stat.h>	// S_IXXX flags
# include <sys/types.h>	// mode_t
# include <unistd.h>	// close()
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int		get_next_line(int fd, char **line);
int		is_newline(char *str);
size_t	ft_strlen(const char *str, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
