#ifndef FDF_H
# define FDF_H

# include "../libft_gnl/libft.h"
# include <mlx.h>
# include <stdio.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080


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
void	read_file(t_fdf *fdf, char *filename);

#endif
