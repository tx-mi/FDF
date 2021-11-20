#include "fdf.h"

void	init(t_img_data *image, t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_window = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fils de fer");
	image->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
}

int	main(int argc, char **argv)
{
	t_fdf		fdf;
	t_img_data	image;


	(void)argv;
	if (argc != 2)
	{
		write(2, "error\n", 6);
		return (1);
	}
	init(&image, &fdf);
	read_file(&fdf, argv[1]);
	int i = 0;
	int j = 0;

	while (i < fdf.height)
	{
		j = 0;
		while (j < fdf.width)
		{
			printf("%3d", fdf.z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	bresenham(5, 5, 700, 5, &image);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_window, image.img, 0, 0);
	mlx_loop(fdf.mlx);

	return (0);
}
