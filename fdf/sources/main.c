#include "fdf.h"

int check(int k)
{
	printf("%d\n", k);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_map		*map;

	if (argc == 2)
	{
		map = map_init();
		fdf = fdf_init(map);
		read_map(argv[1], map);
		fdf->camera = camera_init(fdf);
		draw(fdf, map);
		// mlx_hook(fdf->win, 2, 0, check, fdf)
		setup_control(fdf);
		mlx_loop(fdf->mlx);
	}
	terminate(ERR_USAGE);
	return (0);
}
