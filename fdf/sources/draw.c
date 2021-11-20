#include "fdf.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	int		offset;
	char	*c;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
		c = data->addr + offset;
		*(unsigned int*)c = color;
		// data->addr[offset] = color;
		// data->addr[++offset] = color >> 8;
		// data->addr[++offset] = color >> 16;
		// data->addr[++offset] = 0;
	}
}

void	bresenham(int x0, int y0, int x1, int y1, t_img_data *data)
{
	int delta_x;
	int delta_y;
	int sign_x;
	int sign_y;
	int error[2];

	delta_x = abs(x1 - x0);
	delta_y = -abs(y1 - y0);
	sign_x = sign(x0, x1);
	sign_y = sign(y0, y1);
	error[0] = delta_x + delta_y;
	while (x0 != x1 || y0 != y1)
	{
		my_mlx_pixel_put(data, x0, y0, 0xffffff);
		error[1] = 2 * error[0];
		if (error[1] >= delta_y)
		{
			error[0] += delta_y;
			x0 += sign_x;
		}
		if (error[1] <= delta_x)
		{
			error[0] += delta_x;
			y0 += sign_y;
		}
	}
}
