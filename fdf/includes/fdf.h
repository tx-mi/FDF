#ifndef FDF_H
# define FDF_H

# include "../libft_gnl/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>

# include "error_message.h"
# include "colors.h"
# include "keys.h"

# define WIDTH			1920
# define HEIGHT			1080
# define MENU_WIDTH		250

# define MAX_SMOOTH		50

typedef enum
{
	ISO,
	PARALLEL,
	ROTATIONS,
	SMOOTH,
	CHANGE_COLORS,
}	t_effects;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_camera
{
	t_effects			effects;	
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
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
}						t_map;

typedef struct			s_fdf
{
	int					smooth;
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_camera			*camera;
	t_map				*map;
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

void	draw_backgound(t_fdf *fdf);

void draw(t_fdf *fdf, t_map *map);

// Design
void isometric(int *x, int *y, int z);

t_point design(t_point point, t_fdf *fdf);

// Color
int default_color(int z, t_map *map);

int get_color(t_point current, t_point start, t_point end, t_fdf *fdf);

// Control
void	setup_control(t_fdf *fdf);

// Keys manage
int key_press(int keycode, t_fdf *fdf);

// Management
int	close_fdf(int keycode, t_fdf *fdf);

int	move(int keycode, t_fdf *fdf);

int	zoom(int keycode, t_fdf *fdf);

int	rotate(int keycode, t_fdf *fdf);

int	change_view(int keycode, t_fdf *fdf);

// Effects
void	effects(int *x, int *y, int *z, t_fdf *fdf);

// Utils
double percent(int start, int end, int current);

void terminate(char *s);

int calc_sign(int point0, int point1);

t_point new_point(t_map *map, int x, int y);

int min(int first, int second);

void find_minmax(t_map *map, int *arr);

void	iso(int *x, int *y, int z);

#endif
