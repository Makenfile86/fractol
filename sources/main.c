/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:41:30 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 15:42:18 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl("error, not enough arguments");
		instructions();
		exit(0);
	}
	if (argc > 4)
	{
		ft_putendl("error, too many arguments");
		instructions();
		exit(0);
	}
	get_fractol(argc, argv);
	return (0);
}
