/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autozoom_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:05:16 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 14:08:30 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	maxit100_autozoom_back(t_fractol *f, double re, double im)
{
	int i;

	i = 0;
	while (i < 650)
	{
		auto_zoom_back(re, im, f);
		i++;
	}
}

void	maxit30_autozoom_back(t_fractol *f, double re, double im)
{
	int i;

	i = 0;
	while (i < 270)
	{
		if (i > 89 && i < 219)
		{
			re = -1.490195;
			im = -0.001218;
		}
		if (i >= 219 && i < 359)
		{
			re = -1.492836;
			im = -0.001218;
		}
		auto_zoom_back(re, im, f);
		i++;
	}
}

void	maxit50_autozoom_back(t_fractol *f, double re, double im)
{
	int i;

	i = 0;
	while (i < 325)
	{
		if (i > 100 && i < 200)
		{
			re = -1.402275;
			im = -0.007579;
		}
		if (i >= 200)
		{
			re = -1.410353;
			im = -0.007485;
		}
		auto_zoom_back(re, im, f);
		i++;
	}
}

void	auto_zoom_back(double re, double im, t_fractol *f)
{
	double interpolation;
	double zoom;

	zoom = 0.950;
	interpolation = 1.0 / zoom;
	f->zoomcount -= 5;
	calc_map_view(re, im, interpolation, f);
	pthread(f);
}
