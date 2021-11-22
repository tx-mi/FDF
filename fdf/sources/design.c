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
    point.z *= fdf->camera->zoom / fdf->camera->z_divisor;
    isometric(&(point.x), &(point.y), point.z);
    point.x += (WIDTH / 2) + fdf->camera->x_offset;
    point.y += (HEIGHT - fdf->map->height * fdf->camera->zoom) / 2 + fdf->camera->y_offset;
    return (point);
}
