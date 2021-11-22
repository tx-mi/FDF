#include "fdf.h"

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
		// setup_controls()
		mlx_loop(fdf->mlx);
	}
	terminate(ERR_USAGE);
	return (0);
}
