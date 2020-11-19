/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:40:06 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 14:47:34 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_fractol *f, int keycode)
{
	if (keycode == L_R)
		f->red = f->red + 10;
	if (keycode == B_T)
		f->red = f->red - 10;
	if (keycode == B_G)
		f->green = f->green + 10;
	if (keycode == L_H)
		f->green = f->green - 10;
	if (keycode == L_B)
		f->blue = f->blue + 10;
	if (keycode == L_N)
		f->blue = f->blue - 10;
	pthread(f);
}

void	move(t_fractol *f, int keycode)
{
	if (keycode == 124)
	{
		f->max.re = (f->max.re + f->zoom_adjust);
		f->min.re = (f->min.re + f->zoom_adjust);
		pthread(f);
	}
	if (keycode == 123)
	{
		f->max.re = (f->max.re - f->zoom_adjust);
		f->min.re = (f->min.re - f->zoom_adjust);
		pthread(f);
	}
	if (keycode == 125)
	{
		f->max.im = (f->max.im - f->zoom_adjust);
		f->min.im = (f->min.im - f->zoom_adjust);
		pthread(f);
	}
	if (keycode == 126)
	{
		f->max.im = (f->max.im + f->zoom_adjust);
		f->min.im = (f->min.im + f->zoom_adjust);
		pthread(f);
	}
}

void	choose_color(t_fractol *f)
{
	f->color_factor[0] = 1;
	f->color_factor[1] = 0;
	f->color_shift = 2;
	f->c_i[1] = 1;
	f->c_i[2] = 2;
	f->c_i[3] = 3;
	f->red = 0;
	f->green = 0;
	f->blue = 0;
	if (f->color_style <= 4)
		f->color_style = f->color_style + 1;
	else
		f->color_style = 1;
	get_rgb(f);
	pthread(f);
}

void	next_fractal(t_fractol *f)
{
	void			*mlx_ptr;
	t_fractol		*newf;
	int				nbr;

	newf = NULL;
	nbr = f->fractal;
	mlx_ptr = f->mlx;
	destroy(f);
	free(f);
	if (nbr == 1)
	{
		newf = init(mlx_ptr, 2, "julia");
		mlx_hook(newf->win, 6, (1L << 6), julia_motion, newf);
	}
	else if (nbr == 3)
		newf = init(mlx_ptr, 1, "mandelbrot");
	else if (nbr == 2)
		newf = init(mlx_ptr, 3, "mandelbar");
	pthread(newf);
	mlx_loop(mlx_ptr);
}

int		keypressed(int keycode, t_fractol *f)
{
	if (keycode == ARROW_UP || keycode == ARROW_DOWN ||
			keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		move(f, keycode);
	if (keycode == YKSI || keycode == KAKSI ||
			keycode == KOLME || keycode == NELJA)
		color_factor(f, keycode);
	if (keycode == L_C)
		color_shift(f);
	if (keycode == VIISI || keycode == KUUSI)
		menu(f, keycode);
	if (keycode == L_R || keycode == B_T || keycode == B_G ||
			keycode == L_H || keycode == L_B || keycode == L_N)
		change_color(f, keycode);
	if (keycode == L_V)
		choose_color(f);
	if (keycode == L_X)
		psychedelic(f);
	if (keycode == L_M)
		reset_view(f);
	if (keycode == L_F)
		next_fractal(f);
	if (keycode == MAIN_PAD_ESC)
		exit(1);
	return (0);
}
