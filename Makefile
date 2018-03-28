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

SRC = main.c \
	lists.c \
	links.c \
	let_they_go.c \
	gnl/get_next_line.c

NAME = lem-in

CC = gcc -Wall -Wextra -Werror

IDIR = ./hdr

CFLAGS = -I$(IDIR)

LIBDIR = ./libft
PF_DIR = ./ft_printf


LIBFT = $(LIBDIR)/libft.a

SRCDIR = src

_DEPS = lemin.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(NAME): $(LIBFT) $(OBJ)
			cp libft/libft.a ./
			cp ft_printf/libftprintf.a ./
			$(CC) -o $(NAME) $(OBJ) libft.a libftprintf.a

$(LIBFT):
	make -C $(LIBDIR)
	make -C $(PF_DIR)

clean:
	/bin/rm -rf *.o
	/bin/rm -rf gnl/*.o
	make clean -C $(LIBDIR)
	make clean -C $(PF_DIR)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf libft/libft.a
	/bin/rm -rf libft.a
	/bin/rm -rf ft_printf/libftprintf.a
	/bin/rm -rf libftprintf.a

re : fclean all
