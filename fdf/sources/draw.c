/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:17:28 by mwittenb          #+#    #+#             */
/*   Updated: 2021/11/25 23:12:45 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	int		offset;
	char	*c;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * fdf->size_line) + (x * fdf->bits_per_pixel / 8);
		c = fdf->data_addr + offset;
		*(unsigned int *)c = color;
	}
}

static void	calc_delta_sign(t_point *delta, t_point *sign,
				t_point start, t_point end)
{
	delta->x = abs(end.x - start.x);
	delta->y = -abs(end.y - start.y);
	sign->x = calc_sign(start.x, end.x);
	sign->y = calc_sign(start.y, end.y);
}

void	bresenham(t_point start, t_point end, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	current;
	int		error[2];

	calc_delta_sign(&delta, &sign, start, end);
	current = start;
	error[0] = delta.x + delta.y;
	while (current.x != end.x || current.y != end.y)
	{
		my_mlx_pixel_put(fdf, current.x, current.y,
			get_color(current, start, end, delta));
		error[1] = 2 * error[0];
		if (error[1] >= delta.y)
		{
			error[0] += delta.y;
			current.x += sign.x;
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			current.y += sign.y;
		}
	}
}

void	draw_backgound(t_fdf *fdf)
{
	int	i;
	int	*image;

	i = 0;
	image = (int *)fdf->data_addr;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = BACKGROUND;
		i++;
	}
}

void	draw(t_fdf *fdf, t_map *map)
{
	int	x;
	int	y;

	flick(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				bresenham(design(new_point(map, x, y), fdf),
					design(new_point(map, x + 1, y), fdf), fdf);
			if (y != map->height - 1)
				bresenham(design(new_point(map, x, y), fdf),
					design(new_point(map, x, y + 1), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
