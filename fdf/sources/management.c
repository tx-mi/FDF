/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:05:59 by mwittenb          #+#    #+#             */
/*   Updated: 2021/11/25 23:12:23 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(int keycode, t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	move(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_PAD_RIGHT)
		fdf->camera->x_offset += 8;
	else if (keycode == NUM_PAD_LEFT)
		fdf->camera->x_offset -= 8;
	else if (keycode == NUM_PAD_DOWN)
		fdf->camera->y_offset += 8;
	else
		fdf->camera->y_offset -= 8;
	draw(fdf, fdf->map);
	return (0);
}

int	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_PAD_PLUS)
		fdf->camera->zoom += 2;
	else
		fdf->camera->zoom -= 2;
	draw(fdf, fdf->map);
	return (0);
}

int	rotate(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_PAD_A)
		fdf->camera->gamma += 0.1;
	else if (keycode == MAIN_PAD_D)
		fdf->camera->gamma -= 0.1;
	else if (keycode == MAIN_PAD_S)
		fdf->camera->alpha += 0.1;
	else if (keycode == MAIN_PAD_W)
		fdf->camera->alpha -= 0.1;
	else if (keycode == MAIN_PAD_E)
		fdf->camera->beta += 0.1;
	else
		fdf->camera->beta -= 0.1;
	draw(fdf, fdf->map);
	return (0);
}

int	change_view(int keycode, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (keycode == MAIN_PAD_I)
		fdf->camera->effects = ISO;
	else
		fdf->camera->effects = PARALLEL;
	draw(fdf, fdf->map);
	return (0);
}
