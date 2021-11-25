/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:10:06 by mwittenb          #+#    #+#             */
/*   Updated: 2021/11/25 23:11:58 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_minmax(t_map *map, int *arr)
{
	int	i;

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
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	choose_colors(int choice, t_map *map)
{
	if (choice == 0)
	{
		map->colors_arr[0] = COLOR_DISCO;
		map->colors_arr[1] = COLOR_BRICK_RED;
		map->colors_arr[2] = COLOR_FLAMINGO;
		map->colors_arr[3] = COLOR_JAFFA;
		map->colors_arr[4] = COLOR_SAFFRON;
	}
	else if (choice == 1)
	{
		map->colors_arr[0] = COLOR_PURPLE;
		map->colors_arr[1] = COLOR_PINK;
		map->colors_arr[2] = COLOR_LIGTH_RED;
		map->colors_arr[3] = COLOR_ORANGE;
		map->colors_arr[4] = COLOR_YELLOW;
	}
	else if (choice == 2)
	{
		map->colors_arr[0] = COLOR_BLUE;
		map->colors_arr[1] = COLOR_DARK_PINK;
		map->colors_arr[2] = COLOR_LIGTH_YELLOW;
		map->colors_arr[3] = COLOR_GREEN;
		map->colors_arr[4] = COLOR_LIGTH_BLUE;
	}
}

void	init_colors(int choice, t_map *map)
{
	map->colors_arr = (int *)calloc(5, sizeof(int));
	if (!map->colors_arr)
		terminate(ERR_MAP_INIT);
	choose_colors(choice, map);
}
