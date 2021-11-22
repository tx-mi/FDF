#ifndef FDF_H
# define FDF_H

# include "../libft_gnl/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>

#include "error_message.h"

# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		250


typedef enum
{
	Iso,
	Parallel
}	t_projection;

// typedef struct			s_coord_val
// {
// 	int					z;
// 	int					color;
// 	struct s_coord_val	*next;
// }						t_coord_val;

// typedef struct			s_point
// {
// 	int					x;
// 	int					y;
// 	int					z;
// 	int					color;
// }						t_point;

typedef struct			s_camera
{
	t_projection		projection;
	int					zoom;
	// double				alpha;
	// double				beta;
	// double				gamma;
	// float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_camera;

typedef struct			s_map
{
	int					width;
	int					height;
	// int					*coords_arr;
	int					**z_matrix;
	int					*colors_arr;
	int					z_min;
	int					z_max;
	// int					z_range;
}						t_map;

// typedef struct			s_mouse
// {
// 	char				is_pressed;
// 	int					x;
// 	int					y;
// 	int					previous_x;
// 	int					previous_y;
// }						t_mouse;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_camera			*camera;
	t_map				*map;
	// t_mouse				*mouse;
}						t_fdf;

// Init
t_map *map_init(void);

t_fdf *fdf_init(t_map *map);

t_camera *camera_init(t_fdf *fdf);

// Parse
void read_map(char *filename, t_map *map);

// Utils
double precent(int start, int end, int current);

void terminate(char *s);

int sign(int point0, int point1);


// ///////////////////
// void my_mlx_pixel_put();
// void bresenham();

// void read_file();


#endif
