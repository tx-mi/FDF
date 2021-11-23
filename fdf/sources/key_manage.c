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
	else if (key == MAIN_PAD_A || key == MAIN_PAD_S ||
			key == MAIN_PAD_D || key == MAIN_PAD_W)
		rotate(key, fdf);
	else if (key == MAIN_PAD_I || key == MAIN_PAD_P)
		change_view(key, fdf);
	else if (key == MAIN_PAD_F)
		flicker(fdf);
	return (0);
}
