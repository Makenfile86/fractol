/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:50:55 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 14:54:25 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_complex	calc_mouse_pos(int x, int y, t_fractol *f)
{
	t_complex position;

	position = init_complex((double)x / (WIDTH / (f->max.re - f->min.re))
			+ f->min.re,
			(double)y / (HEIGHT / (f->max.im - f->min.im))
			* -1 + f->max.im);
	return (position);
}

void		calc_map_view(double re, double im, double scale, t_fractol *f)
{
	f->min.re = scale_view(re, f->min.re, scale);
	f->min.im = scale_view(im, f->min.im, scale);
	f->max.re = scale_view(re, f->max.re, scale);
	f->max.im = scale_view(im, f->max.im, scale);
}
