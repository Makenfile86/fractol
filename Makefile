# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 14:45:40 by mkivipur          #+#    #+#              #
#    Updated: 2020/07/02 09:38:34 by mkivipur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = ./sources/main.c ./sources/get_fractal.c ./sources/iterate_fractals.c ./sources/init.c ./sources/error_message.c ./sources/color.c ./sources/draw.c ./sources/controls.c ./sources/instructions.c ./sources/convert.c ./sources/effects.c ./sources/color_palette.c ./sources/color_palette2.c ./sources/auto_zoom.c ./sources/autozoom_back.c ./sources/reset.c ./sources/zoom.c

OBJS = ./*.o

HDR = ./sources/

MLX		= ./miniLibX/

LIBS	= -L libft/ -lft -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) 
	gcc $(OBJS) $(LIBS) -o $(NAME)

$(OBJS): $(SRCS) 
	$(CC) $(FLAGS) -c $(SRCS)
	make re -C ./libft/

clean:
	/bin/rm -f $(OBJS)
	make clean -C ./libft/
fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all
