#include "fdf.h"

static void	free_splitarray(char **array)
{
	size_t i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static int	get_width(char *line)
{
	char	**array;
	int		i;

	array = ft_split(line, ' ');
	i = 0;
	while (array[i])
		i++;
	free_splitarray(array);
	return (i);
}

static void	get_height(t_fdf *fdf, char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	fdf->width = get_width(line);
	fdf->height = 1;

	while (get_next_line(fd, &line) > 0)
	{
		fdf->height++;
		free(line);
		line = NULL;
	}
	free(line);
}

static void	fill_row_matrix(int *row, char *line)
{
	char **nums;
	int i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		row[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;	
	}
	free(nums);
}

void	read_file(t_fdf *fdf, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	get_height(fdf, filename);
	fdf->z_matrix = (int **)malloc(sizeof(int*) * (fdf->height + 1));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fdf->z_matrix[i] = (int *)malloc(sizeof(int) * (fdf->width + 1));
		fill_row_matrix(fdf->z_matrix[i], line);
		free(line);
		line = NULL;
		i++;
	}
	free(line);
	fdf->z_matrix[i] = NULL;
}
