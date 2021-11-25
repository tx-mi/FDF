/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:07:31 by mwittenb          #+#    #+#             */
/*   Updated: 2021/11/25 23:12:06 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	calc_sign(int point0, int point1)
{
	if (point0 < point1)
		return (1);
	else
		return (-1);
}

t_point	new_point(t_map *map, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map->z_matrix[y][x];
	point.color = default_color(point.z, map);
	return (point);
}

int	min(int first, int second)
{
	if (first > second)
		return (second);
	else
		return (first);
}
