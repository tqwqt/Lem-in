# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 16:17:03 by vhavryle          #+#    #+#              #
#    Updated: 2018/03/27 16:17:04 by vhavryle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
	parser.c \
	caster.c \
	flags.c \
	cast_cs.c \
	uni.c \
	cast_ddi.c \
	cast_x.c \
	casto.c

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

IDIR = ./hdr

CFLAGS = -I$(IDIR)

LIBDIR = ./libft



LIBFT = $(LIBDIR)/libft.a

SRCDIR = src

_DEPS = libftprintf.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(LIBFT) $(OBJ)
			cp libft/libft.a ./$(NAME)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

$(LIBFT):
	make -C $(LIBDIR)

clean:
	/bin/rm -rf *.o
	make clean -C $(LIBDIR)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf libft/libft.a

re : fclean all
