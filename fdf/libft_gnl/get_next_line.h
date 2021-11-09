#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <fcntl.h>	// open() and O_XXX flags
# include <sys/stat.h>	// S_IXXX flags
# include <sys/types.h>	// mode_t
# include <unistd.h>	// close()
# include <stdlib.h>
# include <string.h>

int		get_next_line(int fd, char **line);

#endif
