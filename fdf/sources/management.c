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
		fdf->camera->x_offset += 8;
	else if (keycode == NUM_PAD_LEFT)
		fdf->camera->x_offset -= 8;
	else if (keycode == NUM_PAD_DOWN)
		fdf->camera->y_offset += 8;
	else
		fdf->camera->y_offset -= 8;
	draw(fdf, fdf->map);
	return (0);
}

int	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_PAD_PLUS) 
		fdf->camera->zoom += 3;
	else
		fdf->camera->zoom -= 3;
	draw(fdf, fdf->map);
	return (0);
}

int	rotate(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_PAD_A)
		fdf->camera->gamma += 0.1;
	else if (keycode == MAIN_PAD_D)
		fdf->camera->gamma -= 0.1;
	else if (keycode == MAIN_PAD_S)
		fdf->camera->alpha += 0.1;
	else
		fdf->camera->alpha -= 0.1;
	draw(fdf, fdf->map);
	return (0);
}

int	change_view(int keycode, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (keycode == MAIN_PAD_I)
		fdf->camera->effects = ISO;
	else
		fdf->camera->effects = PARALLEL;
	draw(fdf, fdf->map);
	return (0);
}
