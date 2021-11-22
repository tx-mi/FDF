#include "fdf.h"

void	setup_control(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
}
