/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:08:56 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 14:34:02 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_rgb(t_fractol *f)
{
	f->red = 0;
	f->green = 0;
	f->blue = 0;
	if (f->color_style == 1)
		color_bright(f);
	if (f->color_style == 2)
		color_blue(f);
	if (f->color_style == 3)
		color_what(f);
	if (f->color_style == 4)
	{
		f->color_shift = 3;
		color_index(f);
		f->color_factor[0] = 1.50;
		color_crazy(f);
	}
	if (f->color_style == 5)
	{
		f->color_factor[1] = -0.65;
		f->color_factor[0] = 0.70;
		f->green = 30;
		f->blue = 40;
		color_5(f);
	}
}

void	color_index(t_fractol *f)
{
	if (f->color_shift == 1)
	{
		f->c_i[1] = 1;
		f->c_i[2] = 2;
		f->c_i[3] = 3;
	}
	if (f->color_shift == 2)
	{
		f->c_i[1] = 2;
		f->c_i[2] = 3;
		f->c_i[3] = 1;
	}
	if (f->color_shift == 3)
	{
		f->c_i[1] = 3;
		f->c_i[2] = 1;
		f->c_i[3] = 2;
	}
}

int		color_size(t_fractol *f)
{
	int color_size;

	if (f->color_style == 1)
		color_size = 16;
	if (f->color_style == 2 || f->color_style == 5)
		color_size = 8;
	if (f->color_style == 3 || f->color_style == 4)
		color_size = 6;
	return (color_size);
}

void	color_smoothing(int iteration, double re, double im, t_fractol *f)
{
	double square;

	square = sqrt(re + im);
	f->mu = 0;
	f->mu = iteration + 1 - log(log(square)) / (log(2.0));
	f->mu /= color_size(f);
}

void	get_color(int iteration, int x, int y, t_fractol *f)
{
	double		t[2];
	int			clr[2];
	t_color		color;

	clr[0] = (int)f->mu;
	t[1] = f->mu - clr[0];
	t[0] = f->color_factor[0] - t[1];
	t[1] = t[1] + f->color_factor[1];
	clr[0] = clr[0] % color_size(f);
	clr[1] = (clr[0] + 1) % color_size(f);
	if (iteration < (f->max_iteration) && iteration > 0)
	{
		color.channel[f->c_i[0]] = 0;
		color.channel[f->c_i[1]] = (int8_t)f->r[clr[0]] * t[0]
			+ (int8_t)f->r[clr[1]] * t[1] + f->red;
		color.channel[f->c_i[2]] = (int8_t)f->g[clr[0]] * t[0]
			+ (int8_t)f->g[clr[1]] * t[1] + f->green;
		color.channel[f->c_i[3]] = (int8_t)f->b[clr[0]] * t[0]
			+ (int8_t)f->b[clr[1]] * t[1] + f->blue;
	}
	else
		color = color_black();
	put_pixel(f, x, y, color);
}
