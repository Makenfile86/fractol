/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:59:08 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 15:03:06 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	effects(t_fractol *f)
{
	if (f->psychedelic == 1)
		color_shift(f);
	if (f->psychedelic == 2)
		choose_color(f);
	if (f->psychedelic == 3)
	{
		color_shift(f);
		choose_color(f);
	}
}

void	psychedelic(t_fractol *f)
{
	if (f->psychedelic < 3)
		f->psychedelic = f->psychedelic + 1;
	else
		f->psychedelic = 0;
	pthread(f);
}

int		julia_motion(int x, int y, t_fractol *f)
{
	if (x > 125 && x < 450 && y > 125 && y < 450)
	{
		f->k = init_complex(((double)x / WIDTH - 0.2),
				((double)(HEIGHT - y) / HEIGHT - 0.2));
		effects(f);
		pthread(f);
	}
	return (0);
}

void	color_shift(t_fractol *f)
{
	if (f->color_shift <= 2)
		f->color_shift = f->color_shift + 1;
	else
		f->color_shift = 1;
	color_index(f);
	pthread(f);
}

void	color_factor(t_fractol *f, int button)
{
	if (button == YKSI)
		f->color_factor[0] = f->color_factor[0] + 0.05;
	if (button == KAKSI)
		f->color_factor[0] = f->color_factor[0] - 0.05;
	if (button == KOLME)
		f->color_factor[1] = f->color_factor[1] + 0.05;
	if (button == NELJA)
		f->color_factor[1] = f->color_factor[1] - 0.05;
	pthread(f);
}
