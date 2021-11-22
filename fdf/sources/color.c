#include "fdf.h"

int default_color(int z, t_map *map)
{
    double percentage;

    percentage = percent(map->z_min, map->z_max, z);
    if (percentage < 0.2)
        return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int get_color(t_point current, t_point start, t_point end)
{
    if (end.z)
        return (end.color);
    else if (start.z)
        return (start.color);
    return (current.color);
}