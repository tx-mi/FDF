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
		fdf->camera->z_zoom += 5;
	else
		fdf->camera->z_zoom -= 5;
	draw(fdf, fdf->map);
	return (0);
}
