#include "fdf.h"

t_map *map_init(void)
{
    t_map *map;

    map = (t_map *)ft_calloc(1, sizeof(t_map));
    if (!map)
        terminate(ERR_MAP_INIT);
    map->width = 0;
    map->height = 0;
    map->colors_arr = NULL;
    map->z_matrix = NULL;
    map->z_max = 0;
    map->z_min = 0;
    return (map);
}

t_fdf *fdf_init(t_map *map)
{
    t_fdf *fdf;

    fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
    if (!fdf)
        terminate(ERR_FDF_INIT);
    fdf->mlx = mlx_init();
    fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
    fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
    fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
                                       &(fdf->size_line), &(fdf->endian));
    fdf->map = map;
    return (fdf);
}

t_camera *camera_init(t_fdf *fdf)
{
    t_camera	*camera;

    camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
    if (!camera)
		terminate(ERR_CAMERA_INIT);
	// camera->alpha = 0;
	// camera->beta = 0;
	// camera->gamma = 0;
	camera->z_divisor = 3;
    camera->zoom = min(WIDTH / fdf->map->width / 2, HEIGHT / fdf->map->height / 2);
    camera->x_offset = 0;
    camera->y_offset = 0;
	return (camera);;
}
