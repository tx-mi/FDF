#include "fdf.h"

void	effects(int *x, int *y, int *z, t_fdf *fdf)
{
	if (fdf->camera->effects == ISO)
		iso(x, y, *z);
	// else if (fdf->camera->effects == PARALLEL)
}
