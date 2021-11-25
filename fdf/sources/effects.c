#include "fdf.h"

void	effects(int *x, int *y, int *z, t_fdf *fdf)
{
	if (fdf->camera->effects != PARALLEL)
		iso(x, y, *z);
}

int	flicker(t_fdf *fdf)
{
	if (fdf->flicker == 0)
		fdf->flicker = 1;
	else
		fdf->flicker = 0;
	draw(fdf, fdf->map);
	return (0);
}

void	flick(t_fdf *fdf)
{
	if (fdf->flicker == 0)
		draw_backgound(fdf);
	else if (fdf->flicker != 0 && fdf->flicker < 2)
		fdf->flicker++;
	else if (fdf->flicker == 2)
	{
		draw_backgound(fdf);
		fdf->flicker = 1;
	}
}

int	z_scale(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_PAD_Z)
		fdf->camera->z_divisor -= 0.1;
	else
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	draw(fdf, fdf->map);
	return (0);
}

int	change_colors(int keycode, t_fdf* fdf)
{
	int	choice;

	if (fdf->map->colors_arr[0] == COLOR_DISCO)
		choice = 0;
	else if (fdf->map->colors_arr[0] == COLOR_PURPLE)
		choice = 1;
	else if (fdf->map->colors_arr[0] == COLOR_BLUE)
		choice = 2;
	if (choice == 2)
		choice = 0;
	else
		choice++;
	init_colors(choice, fdf->map);
	draw(fdf, fdf->map);
	return (0);
}

