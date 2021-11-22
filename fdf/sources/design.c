#include "fdf.h"

void isometric(int *x, int *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

t_point design(t_point point, t_fdf *fdf)
{
    point.x *= fdf->camera->zoom;
    point.y *= fdf->camera->zoom;
    isometric(&(point.x), &(point.y), point.z);
    return (point);
}
