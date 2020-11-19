/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:13:38 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 15:16:36 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_fractol(t_fractol *f)
{
	f->bits_per_pixel = 32;
	f->size_line = 600;
	f->endian = 0;
	f->max_iteration = 100;
	f->org_mxiter = f->max_iteration;
	f->min = init_complex(-2.0, -2.0);
	f->max.re = 2.0;
	f->max.im = f->min.im
		+ (f->max.re - f->min.re) * HEIGHT / WIDTH;
	f->k = init_complex(-0.4, 0.6);
	f->color_shift = 2;
	f->julia = 0;
	f->zoom_adjust = 0.1;
	f->menu = 1;
	f->color_factor[0] = 1;
	f->color_factor[1] = 0;
	f->c_i[1] = 1;
	f->c_i[2] = 2;
	f->c_i[3] = 3;
	f->c_i[0] = 0;
	f->color_style = 4;
	f->psychedelic = 0;
	f->zoomcount = 0;
}

t_fractol	*init(void *mlx_ptr, int f_nbr, char *name)
{
	t_fractol *f;

	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))\
		exit(1);
	f->win = mlx_new_window(mlx_ptr, W_WIDTH, W_HEIGHT, name);
	f->mlx = mlx_ptr;
	mlx_key_hook(f->win, keypressed, f);
	if (!(f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT)))
		exit(1);
	set_fractol(f);
	get_rgb(f);
	f->data_addr = mlx_get_data_addr(
		f->image,
		&(f->bits_per_pixel),
		&(f->size_line),
		&(f->endian));
	f->fractal = f_nbr;
	mlx_mouse_hook(f->win, zoom, f);
	return (f);
}
