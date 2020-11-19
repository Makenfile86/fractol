/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:16:59 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/03 10:56:11 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_text(t_fractol *f)
{
	char	*iteration;
	char	*psychedelic;
	char	*zoom;

	iteration = ft_itoa(f->max_iteration);
	psychedelic = ft_itoa(f->psychedelic);
	zoom = ft_itoa(f->zoomcount);
	mlx_put_image_to_window(f->mlx, f->win, f->image, 0, 0);
	mlx_string_put(f->mlx, f->win, 5, 10, COLOR_ORANGE,
			"Press 5 to show Controls menu");
	mlx_string_put(f->mlx, f->win, 475, 10, 0xFFFFDF, "ITER: ");
	mlx_string_put(f->mlx, f->win, 525, 10, 0xFFFFDF, iteration);
	mlx_string_put(f->mlx, f->win, 475, 25, 0xFFFFDF, "PSYCH EFF: ");
	mlx_string_put(f->mlx, f->win, 575, 25, 0xFFFFDF, psychedelic);
	mlx_string_put(f->mlx, f->win, 475, 40, 0xFFFFDF, "ZOOMx: ");
	mlx_string_put(f->mlx, f->win, 540, 40, 0xFFFFDF, zoom);
	free(iteration);
	free(psychedelic);
	free(zoom);
}

void	color_text(t_fractol *f)
{
	char	*red;
	char	*green;
	char	*blue;

	red = ft_itoa(f->red);
	green = ft_itoa(f->green);
	blue = ft_itoa(f->blue);
	mlx_string_put(f->mlx, f->win, 510, 60, 0xFFFFDF, "RED:");
	mlx_string_put(f->mlx, f->win, 570, 60, 0xFFFFDF, red);
	mlx_string_put(f->mlx, f->win, 510, 80, 0xFFFFDF, "GREEN:");
	mlx_string_put(f->mlx, f->win, 570, 80, 0xFFFFDF, green);
	mlx_string_put(f->mlx, f->win, 510, 100, 0xFFFFDF, "BLUE:");
	mlx_string_put(f->mlx, f->win, 570, 100, 0xFFFFDF, blue);
	free(red);
	free(green);
	free(blue);
}

void	menu2(t_fractol *f, int color)
{
	mlx_string_put(f->mlx, f->win, 5, 685, color,
	"Color pallet   - Press V to change color pallet");
	mlx_string_put(f->mlx, f->win, 5, 700, color,
	"Color factor   - Press 1 or Press 3 to blend colors more, 3 or 4 to less");
	mlx_string_put(f->mlx, f->win, 5, 715, color,
	"Zoom           - Use the mouse scroll to Zoom in and out");
	mlx_string_put(f->mlx, f->win, 5, 730, color,
	"Autozoom       - Press Mouse2 to autozoom");
	mlx_string_put(f->mlx, f->win, 5, 745, color,
	"Reset view     - Press M to reset the view");
	mlx_string_put(f->mlx, f->win, 5, 760, color,
	"Julia motion   - Move your mouse in the middle of the set for motion");
	mlx_string_put(f->mlx, f->win, 5, 775, color,
	"Psychedelic eff CAUTION: Flashing lights in ZOOM or JULIA) Press X");
	mlx_string_put(f->mlx, f->win, 5, 790, color,
	"Close Menu     - Press 6");
	mlx_string_put(f->mlx, f->win, 5, 805, color,
	"Close Program  - Press ESC");
}

void	menu(t_fractol *f, int keycode)
{
	int color;

	color = COLOR_ORANGE;
	if (keycode == KUUSI)
	{
		f->menu = 0;
		color = COLOR_BLACK;
	}
	else
		f->menu = 1;
	mlx_string_put(f->mlx, f->win, 5, 610, color,
		"Change Fractal - Press 'F'");
	mlx_string_put(f->mlx, f->win, 5, 625, color,
		"Move           - Use Key_Arrows to move");
	mlx_string_put(f->mlx, f->win, 5, 640, color,
		"Color Shift    - Press: C to change from red to blue to green");
	mlx_string_put(f->mlx, f->win, 5, 655, color,
		"Add color      - Press: R to add color red, G for green, B for blue");
	mlx_string_put(f->mlx, f->win, 5, 670, color,
		"Less color     - Press: T for less red, H for green, N for blue");
	menu2(f, color);
	pthread(f);
}
