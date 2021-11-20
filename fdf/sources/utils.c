#include "fdf.h"

double  precent(int start, int end, int current)
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

void    terminate(char *s)
{
    if (errno == 0)
        ft_putendl_fd(s, 2);
    else
        perror(s);
    exit(1);
}

int	sign(int point0, int point1) 
{
	if (point0 < point1)
		return (1);
	else
		return (-1);
}
