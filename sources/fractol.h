/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:03:39 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/02 15:12:59 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "math.h"
# include "mlx.h"
# include "pthread.h"
# include "key_macos.h"

# define THREAD_WIDTH 12
# define THREAD_NUMBER 50
# define WIDTH		600
# define HEIGHT		600
# define W_WIDTH	900
# define W_HEIGHT	900
# define COLOR_ORANGE		0xFFFF9800
# define COLOR_BLACK		0xFF000000

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
	double		re;
	double		im;
}					t_complex;

typedef struct		s_fractol
{
	t_complex		min;
	t_complex		max;
	t_complex		scale;
	t_complex		c;
	t_complex		k;
	int				r[16];
	int				g[16];
	int				b[16];
	int				menu;
	void			*win;
	void			*mlx;
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				fractol_nbr;
	int				max_iteration;
	int				org_mxiter;
	int				color_shift;
	int				fractal;
	int				start_line;
	int				finish_line;
	int				julia;
	double			zoom_adjust;
	int				zoomcount;
	int				red;
	int				green;
	int				blue;
	int				c_i[4];
	int				color_style;
	double			mu;
	double			color_factor[2];
	int				psychedelic;
}					t_fractol;

void				get_fractol(int arg_nbr, char **argument);
void				set_fractol(t_fractol *f);
t_fractol			*init(void *mlx_ptr, int fractol_nbr, char *name);
void				set_data(t_fractol *f);
void				draw_fractal(t_fractol *f);
void				put_pixel(t_fractol *f, int x, int y, t_color color);
t_complex			init_complex(double re, double im);
void				get_color(int iteration, int x, int y, t_fractol *f);
int					iterate_mandelbrot(t_fractol *f);
int					keypressed(int keycode, t_fractol *f);
void				move(t_fractol *f, int keycode);
int					iterate_julia(t_fractol *f);
int					iterate_mandelbar(t_fractol *f);
int					julia_motion(int x, int y, t_fractol *f);
void				pthread(t_fractol *f);
double				scale_view(double org_view, double view, double scale);
void				color_smoothing(int iteration, double re,
		double im, t_fractol *f);
void				color_shift(t_fractol *f);
void				color_index(t_fractol *f);
void				color_factor(t_fractol *f, int button);
void				change_color(t_fractol *f, int keycode);
void				get_rgb(t_fractol *f);
void				help_text(t_fractol *f);
void				color_text(t_fractol *f);
void				instructions(void);
void				menu(t_fractol *f, int keycode);
void				menu2(t_fractol *f, int color);
void				choose_color(t_fractol *f);
void				color_bright(t_fractol *f);
void				color_bright2(t_fractol *f);
void				color_bright3(t_fractol *f);
void				color_blue(t_fractol *f);
void				color_what(t_fractol *f);
void				color_crazy(t_fractol *f);
void				color_5(t_fractol *f);
int					color_size(t_fractol *f);
t_color				color_black(void);
int					zoom(int button, int x, int y, t_fractol *f);
double				adjust_zoom(int button, double zoom, t_fractol *f);
void				select_autozoom(t_fractol *f);
void				auto_zoom(double re, double im, t_fractol *f);
void				auto_zoom_back(double re, double im, t_fractol *f);
void				maxit30_autozoom(t_fractol *f, double re, double im);
void				maxit30_autozoom_back(t_fractol *f, double re, double im);
void				maxit50_autozoom(t_fractol *f, double re, double im);
void				maxit50_autozoom_back(t_fractol *f, double re, double im);
void				maxit100_autozoom(t_fractol *f, double re, double im);
void				maxit100_autozoom_back(t_fractol *f, double re, double im);
t_complex			calc_mouse_pos(int x, int y, t_fractol *f);
void				calc_map_view(double re, double im,
		double scale, t_fractol *f);
void				reset_view(t_fractol *f);
void				next_fractal(t_fractol *f);
void				effects(t_fractol *f);
void				psychedelic(t_fractol *f);
void				select_autozoom(t_fractol *f);
void				error_message(void);
void				destroy(t_fractol *f);

#endif
