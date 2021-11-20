#ifndef FDF_H
# define FDF_H

# include "../libft_gnl/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>


# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800


typedef struct	s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct	s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;

	void	*mlx;
	void	*mlx_window;
}			t_fdf;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void bresenham(int x0, int y0, int x1, int y1, t_img_data *data);
void read_file(t_fdf *fdf, char *filename);

int sign(int point0, int point1);
#endif
