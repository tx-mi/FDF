#include "fdf.h"

int close_fdf(int keycode, t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	move(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_PAD_RIGHT)
		fdf->camera->x_offset += 5;
	else if (keycode == NUM_PAD_LEFT)
		fdf->camera->x_offset -= 5;
	else if (keycode == NUM_PAD_DOWN)
		fdf->camera->y_offset += 5;
	else
		fdf->camera->y_offset -= 5;
	draw(fdf, fdf->map);
	return (0);
}

int	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_PAD_PLUS) 
		fdf->camera->zoom += 1;
	else
		fdf->camera->zoom -= 1;
	draw(fdf, fdf->map);
	return (0);
}
