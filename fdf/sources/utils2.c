#include "fdf.h"

void find_minmax(t_map *map, int *arr)
{
    int i;

    i = 0;
    while (i < map->width)
    {
        if (arr[i] > map->z_max)
            map->z_max = arr[i];
        if (arr[i] < map->z_min)
            map->z_min = arr[i];
        i++;
    }
}

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
