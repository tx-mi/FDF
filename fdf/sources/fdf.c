#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	while (argc > 0)
	{
		fd = open(argv[argc], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
			free(line);
			line = NULL;
		}
		free(line);
		argc--;
	}
	return (0);
}
