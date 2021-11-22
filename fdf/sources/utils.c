#include "fdf.h"

double precent(int start, int end, int current)
{
    double  placement;
    double  distance;

    placement = current - start;
    distance = end - current;
    if (distance == 0)
        return (1.0);
    else
        return (placement / distance);
}

void terminate(char *s)
{
    if (errno == 0)
        ft_putendl_fd(s, 2);
    else
        perror(s);
    exit(1);
}

int calc_sign(int point0, int point1) 
{
	if (point0 < point1)
		return (1);
	else
		return (-1);
}

t_point new_point(t_map *map, int x, int y)
{
    t_point point;

    point.x = x;
    point.y = y;
    point.z = map->z_matrix[y][x];
    if (point.z)
        point.color = 0xff0000;
    else
        point.color = 0xffffff;
    return (point);
}
