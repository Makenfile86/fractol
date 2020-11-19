/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:42:49 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/03 11:01:13 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		select_autozoom(t_fractol *f)
{
	reset_view(f);
	if (f->max_iteration == 30)
		maxit30_autozoom(f, -1.480000, -0.020000);
	if (f->max_iteration == 50)
		maxit50_autozoom(f, -1.406667, -0.006067);
	if (f->max_iteration >= 100)
		maxit100_autozoom(f, -0.741726, -0.202203);
}

double		scale_view(double org_view, double view, double scale)
{
	double new_view;

	new_view = (org_view + ((view - org_view) * scale));
	return (new_view);
}

double		adjust_zoom(int button, double zoom, t_fractol *f)
{
	if (button == 5)
	{
		zoom = 0.90;
		f->zoom_adjust = f->zoom_adjust * 1.1;
		f->zoomcount -= 10;
		if (f->max_iteration > f->org_mxiter)
			f->max_iteration -= 1;
	}
	if (button == 4)
	{
		zoom = 1.1;
		f->zoom_adjust = f->zoom_adjust / 1.1;
		f->zoomcount += 10;
		if (f->max_iteration < 120)
			f->max_iteration += 1;
	}
	return (zoom);
}

int			zoom(int button, int x, int y, t_fractol *f)
{
	t_complex	mouse;
	double		scale;
	double		zoom;

	zoom = 0;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		mouse = calc_mouse_pos(x, y, f);
		zoom = adjust_zoom(button, zoom, f);
		scale = 1.0 / zoom;
		calc_map_view(mouse.re, mouse.im, scale, f);
		effects(f);
		pthread(f);
	}
	if (button == M_2)
		select_autozoom(f);
	return (0);
}
