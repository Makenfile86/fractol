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

void	destroy(t_fractol *f)
{
	ft_bzero(f->data_addr, 600 * 600 * 4);
	mlx_destroy_image(f->mlx, f->image);
	mlx_destroy_window(f->mlx, f->win);
}

void	reset_view(t_fractol *f)
{
	f->zoomcount = 0;
	f->zoom_adjust = 0.1;
	f->max_iteration = f->org_mxiter;
	f->min = init_complex(-2.0, -2.0);
	f->max.re = 2.0;
	f->max.im = f->min.im
		+ (f->max.re - f->min.re) * HEIGHT / WIDTH;
	f->k = init_complex(-0.4, 0.6);
	pthread(f);
}
