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
