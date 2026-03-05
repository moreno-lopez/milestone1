# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: horarivo <horarivo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 07:05:54 by horarivo'         #+#    #+#              #
#    Updated: 2026/02/16 09:08:36 by horarivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a

SRC =	ft_printf.c ft_putaddr.c ft_puthex.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putunsigned.c

HEADER = ft_printf.h

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
