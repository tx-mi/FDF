#ifndef FDF_H
# define FDF_H

# include "../libft_gnl/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>

#include "error_message.h"
#include "colors.h"

# define WIDTH			800
# define HEIGHT			800
// # define MENU_WIDTH		250


typedef enum
{
	Iso,
	Parallel
}	t_perspective;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_camera
{
	t_perspective		perspective;
	int					zoom;
	// double				alpha;
	// double				beta;
	// double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_camera;

typedef struct			s_map
{
	int					width;
	int					height;
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

// Draw
void my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

void bresenham(t_point start, t_point end, t_fdf *fdf);

void draw(t_fdf *fdf, t_map *map);

// Design
void isometric(int *x, int *y, int z);

t_point design(t_point point, t_fdf *fdf);

// Color
int default_color(int z, t_map *map);

int get_color(t_point current, t_point start, t_point end);

// Utils
double percent(int start, int end, int current);

void terminate(char *s);

int calc_sign(int point0, int point1);

t_point new_point(t_map *map, int x, int y);

int min(int first, int second);

void find_minmax(t_map *map, int *arr);

#endif
