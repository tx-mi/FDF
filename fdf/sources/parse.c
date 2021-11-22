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
	if (!array)
		terminate(ERR_MAP);
	i = 0;
	while (array[i])
		i++;
	free_splitarray(array);
	return (i);
}

static void	get_height(t_map *map, char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		terminate(ERR_MAP);
	get_next_line(fd, &line);
	map->width = get_width(line);
	map->height = 1;

	while (get_next_line(fd, &line) > 0)
	{
		map->height++;
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
	if (!nums)
		terminate(ERR_MAP);
	i = 0;
	while (nums[i])
	{
		row[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;	
	}
	row[i] = 0;
	free(nums);
}

void read_map(char *filename, t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		terminate(ERR_MAP);
	get_height(map, filename);
	map->z_matrix = (int **)malloc(sizeof(int*) * (map->height + 1));
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map->z_matrix[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		if (!(map->z_matrix[i]))
			terminate(ERR_MAP);
		fill_row_matrix(map->z_matrix[i], line);
		find_minmax(map, map->z_matrix[i]);
		free(line);
		line = NULL;
		i++;
	}
	free(line);
	map->z_matrix[i] = NULL;
}
