/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:54:46 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 14:58:41 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *f, int x, int y, t_color color)
{
	int i;

	i = (x * f->bits_per_pixel / 8) + (y * f->size_line);
	f->data_addr[i] = color.channel[3];
	f->data_addr[++i] = color.channel[2];
	f->data_addr[++i] = color.channel[1];
	f->data_addr[++i] = color.channel[0];
}

void	draw_fractal(t_fractol *f)
{
	int			y;
	int			x;

	y = f->start_line;
	while (y < f->finish_line)
	{
		f->c.im = f->max.im - y * f->scale.im;
		x = 0;
		while (x < WIDTH)
		{
			f->c.re = f->min.re + x * f->scale.re;
			if (f->fractal == 1)
				get_color(iterate_mandelbrot(f), x, y, f);
			if (f->fractal == 2)
				get_color(iterate_julia(f), x, y, f);
			if (f->fractal == 3)
				get_color(iterate_mandelbar(f), x, y, f);
			x++;
		}
		y++;
	}
}

void	pthread(t_fractol *f)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	f->scale = init_complex(
		(f->max.re - f->min.re) / (WIDTH - 1),
		(f->max.im - f->min.im) / (HEIGHT - 1));
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)f, sizeof(t_fractol));
		tab[i].start_line = THREAD_WIDTH * i;
		tab[i].finish_line = THREAD_WIDTH * (i + 1);
		if (pthread_create(&t[i], NULL,
			(void *(*)(void *))draw_fractal, (void *)&tab[i]))
			exit(1);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	help_text(f);
	color_text(f);
}
