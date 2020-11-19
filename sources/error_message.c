/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:16:59 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/03 10:56:47 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instructions(void)
{
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl(NULL);
	ft_putendl("You can use 1 or all of the fractals at a time");
	ft_putendl(NULL);
	ft_putendl("List of fractals:");
	ft_putendl(" <mandelbrot> ");
	ft_putendl(" <julia> ");
	ft_putendl(" <mandelbar> ");
}

void	error_message(void)
{
	ft_putendl("Invalid fractal name");
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl(NULL);
	ft_putendl("You can use 1 or all of the fractals at a time");
	ft_putendl(NULL);
	ft_putendl("List of fractals:");
	ft_putendl(" <mandelbrot> ");
	ft_putendl(" <julia> ");
	ft_putendl(" <mandelbar> ");
	exit(1);
}
