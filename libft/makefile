# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anikkane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 10:35:34 by anikkane          #+#    #+#              #
#    Updated: 2019/11/04 11:17:38 by anikkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Werror -Wall -Wextra

SRC = ft_atoi.c	ft_isalpha.c	ft_isprint.c	ft_memccpy.c	ft_memcpy.c	ft_memset.c	ft_putendl.c	ft_putnbr_fd.c	ft_strcat.c	ft_strcmp.c	ft_strdup.c	ft_striteri.c	ft_strlen.c	ft_strncat.c	ft_strnequ.c	ft_strrchr.c	ft_strsub.c	ft_toupper.c ft_bzero.c	ft_isascii.c	ft_itoa.c	ft_memchr.c	ft_memdel.c	ft_putchar.c	ft_putendl_fd.c	ft_putstr.c	ft_strchr.c	ft_strcpy.c	ft_strequ.c	ft_strjoin.c	ft_strmap.c	ft_strncmp.c	ft_strnew.c	ft_strsplit.c	ft_strtrim.c	 ft_isalnum.c	ft_isdigit.c	ft_memalloc.c	ft_memcmp.c	ft_memmove.c	ft_putchar_fd.c	ft_putnbr.c	ft_putstr_fd.c	ft_strclr.c	ft_strdel.c	ft_striter.c	ft_strlcat.c	ft_strmapi.c	ft_strncpy.c	ft_strnstr.c	ft_strstr.c	ft_tolower.c	ft_isnegative.c ft_isspace.c

LIBRARY_FILES = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I ./ -c $(SRC) 
	ar rc libft.a *.o
	ranlib libft.a

clean:
	/bin/rm -f $(LIBRARY_FILES) 

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
