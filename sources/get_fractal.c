/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:57:19 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/08 10:56:18 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_fractol(int arg_nbr, char **argument)
{
	void		*mlx_ptr;
	t_fractol	*f;

	mlx_ptr = mlx_init();
	f = NULL;
	while (arg_nbr > 1)
	{
		if (ft_strcmp("mandelbrot", argument[arg_nbr - 1]) == 0)
			f = init(mlx_ptr, 1, "mandelbrot");
		if (ft_strcmp("julia", argument[arg_nbr - 1]) == 0)
		{
			f = init(mlx_ptr, 2, "julia");
			mlx_hook(f->win, 6, (1L << 6), julia_motion, f);
		}
		if (ft_strcmp("mandelbar", argument[arg_nbr - 1]) == 0)
			f = init(mlx_ptr, 3, "mandelbar");
		if (f != NULL)
			pthread(f);
		arg_nbr--;
	}
	if (f == NULL)
		error_message();
	instructions();
	mlx_loop(mlx_ptr);
}
