/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:33:52 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 15:37:33 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		iterate_mandelbar(t_fractol *f)
{
	int			iteration;
	int			added_iter;
	t_complex	z;
	t_complex	v;

	added_iter = 0;
	iteration = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((z.re * z.re + z.im * z.im <= 4)
			&& iteration < f->max_iteration)
	{
		z = init_complex(z.re * z.re - z.im * z.im + f->c.re,
				-2.0 * z.re * z.im + f->c.im);
		iteration++;
	}
	while (added_iter < 3)
	{
		z = init_complex(z.re * z.re - z.im * z.im + f->c.re,
				-2.0 * z.re * z.im + f->c.im);
		v = init_complex(z.re * z.re, z.im * z.im);
		added_iter++;
	}
	v = init_complex(z.re * z.re, z.im * z.im);
	color_smoothing(iteration, v.re, v.im, f);
	return (iteration);
}

int		iterate_julia(t_fractol *f)
{
	int			iteration;
	int			added_iter;
	t_complex	z;
	t_complex	v;

	added_iter = 0;
	iteration = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((z.re * z.re + z.im * z.im <= 4)
			&& iteration < f->max_iteration)
	{
		z = init_complex(z.re * z.re - z.im * z.im + f->k.re,
				2.0 * z.re * z.im + f->k.im);
		iteration++;
	}
	while (added_iter < 3)
	{
		z = init_complex(z.re * z.re - z.im * z.im + f->k.re,
				2.0 * z.re * z.im + f->c.im);
		v = init_complex(z.re * z.re, z.im * f->k.im);
		added_iter++;
	}
	v = init_complex(z.re * z.re, z.im * z.im);
	color_smoothing(iteration, v.re, v.im, f);
	return (iteration);
}

int		iterate_mandelbrot(t_fractol *f)
{
	int			iteration;
	int			added_iter;
	t_complex	z;
	t_complex	v;

	added_iter = 0;
	iteration = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((z.re * z.re + z.im * z.im <= 4)
			&& iteration < f->max_iteration)
	{
		z = init_complex(z.re * z.re - z.im * z.im + f->c.re,
				2.0 * z.re * z.im + f->c.im);
		iteration++;
	}
	while (added_iter < 3)
	{
		z = init_complex(z.re * z.re - z.im * z.im + f->c.re,
				2.0 * z.re * z.im + f->c.im);
		v = init_complex(z.re * z.re, z.im * z.im);
		added_iter++;
	}
	v = init_complex(z.re * z.re, z.im * z.im);
	color_smoothing(iteration, v.re, v.im, f);
	return (iteration);
}
