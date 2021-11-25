#include "fdf.h"

/*
** Color of z-level
*/

int	default_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (map->colors_arr[0]);
	else if (percentage < 0.4)
		return (map->colors_arr[1]);
	else if (percentage < 0.6)
		return (map->colors_arr[2]);
	else if (percentage < 0.8)
		return (map->colors_arr[3]);
	else
		return (map->colors_arr[4]);
}

/*
** Gradient
*/

static int	get_intencity(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + (end * percentage)));
}

static int	get_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

int	get_color(t_point current, t_point start, t_point end, t_point detla)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;

	if (current.color == end.color)
		return (current.color);
	if (detla.y > detla.x)
		percentage = percent(start.y, end.y, current.y);
	else
		percentage = percent(start.x, end.x, current.x);
	red = get_intencity((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF,
			percentage);
	green = get_intencity((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF,
			percentage);
	blue = get_intencity(start.color & 0xFF,
			end.color & 0xFF,
			percentage);
	return (get_rgb(red, green, blue));
}
