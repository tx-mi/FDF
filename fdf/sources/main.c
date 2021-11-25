/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:12:57 by mwittenb          #+#    #+#             */
/*   Updated: 2021/11/25 22:14:09 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_map		*map;

	if (argc == 2)
	{
		map = map_init();
		fdf = fdf_init(map);
		read_map(argv[1], map);
		fdf->camera = camera_init(fdf);
		draw(fdf, map);
		mlx_hook(fdf->win, 2, 0, key_press, fdf);
		mlx_loop(fdf->mlx);
	}
	terminate(ERR_USAGE);
	return (0);
}
