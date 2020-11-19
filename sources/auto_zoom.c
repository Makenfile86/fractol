/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:51:28 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 14:03:39 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	auto_zoom(double re, double im, t_fractol *f)
{
	double interpolation;
	double zoom;

	zoom = 1.025;
	f->zoomcount += 3;
	interpolation = 1.0 / zoom;
	calc_map_view(re, im, interpolation, f);
	pthread(f);
}

void	maxit100_autozoom(t_fractol *f, double re, double im)
{
	int			i;
	t_complex	mouse;

	i = 0;
	mouse = init_complex(re, im);
	while (i < 1350)
	{
		if (i % 20 == 0 && f->max_iteration <= 160)
			f->max_iteration = f->max_iteration + 1;
		if (i >= 599 && i < 726)
			mouse = calc_mouse_pos(166, 181, f);
		if (i >= 726 && i < 849)
			mouse = calc_mouse_pos(217, 270, f);
		if (i >= 850 && i < 999)
			mouse = calc_mouse_pos(261, 204, f);
		if (i >= 1000 & i < 1149)
			mouse = calc_mouse_pos(405, 130, f);
		if (i >= 1150 && i < 1299)
			mouse = calc_mouse_pos(364, 387, f);
		if (i >= 1300)
			mouse = calc_mouse_pos(483, 365, f);
		auto_zoom(mouse.re, mouse.im, f);
		i++;
	}
	maxit100_autozoom_back(f, mouse.re, mouse.im);
}

void	maxit50_autozoom(t_fractol *f, double re, double im)
{
	int i;

	i = 0;
	while (i < 600)
	{
		if (i > 219 && i <= 400)
		{
			re = -1.402353;
			im = -0.007585;
		}
		if (i > 400 && i < 550)
		{
			re = -1.402275;
			im = -0.007579;
		}
		if (i >= 550)
			im = -0.007578;
		auto_zoom(re, im, f);
		i++;
	}
	maxit50_autozoom_back(f, -1.402275, -0.007578);
}

void	maxit30_autozoom(t_fractol *f, double re, double im)
{
	int i;

	i = 0;
	while (i < 500)
	{
		if (i > 89 && i < 219)
		{
			re = -1.490836;
			im = -0.001218;
		}
		if (i >= 219 && i < 359)
		{
			re = -1.490195;
			im = -0.001218;
		}
		if (i >= 359)
		{
			re = -1.490199;
			im = -0.001172;
		}
		auto_zoom(re, im, f);
		i++;
	}
	maxit30_autozoom_back(f, -1.490199, -0.001172);
}
