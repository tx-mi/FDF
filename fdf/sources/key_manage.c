#include "fdf.h"

int key_press(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_ESC)
		close_fdf(key, fdf);
	else if (key == NUM_PAD_DOWN || key == NUM_PAD_LEFT ||
			key == NUM_PAD_RIGHT || key == NUM_PAD_UP)
		move(key, fdf);
	else if (key == MAIN_PAD_PLUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	return (0);
}
