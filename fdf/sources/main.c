#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_map		*map;


	(void)argv;
	if (argc != 2)
	{
		map = map_init();
		fdf = fdf_init(map);
		if (read_map() == -1)
		fdf->camera = camera_init(fdf);
		// draw()
		// setup_controls()
		mlx_loop(fdf->mlx);
	}
	terminate(ERR_USAGE);
	return (1);
	// while (i < fdf.height)
	// {
	// 	j = 0;
	// 	while (j < fdf.width)
	// 	{
	// 		printf("%3d", fdf.z_matrix[i][j]);
	// 		j++;
	// 	}

	return (0);
}
