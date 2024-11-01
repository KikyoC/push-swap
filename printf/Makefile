# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 09:40:08 by togauthi          #+#    #+#              #
#    Updated: 2024/11/01 11:56:24 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = printf.c \
utils/ft_putstr.c \
utils/ft_putchar.c \
utils/ft_putnbr_base.c \
utils/ft_putunbr.c \
utils/ft_putunbr_base.c \
utils/ft_strlen.c \
utils/ft_print_mem.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME) move

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@ar -rc $(NAME) $^

move:
	@mv $(OBJS) ../objects

clean:
		@rm -f $(OBJS);

fclean: clean
		@rm -f $(NAME);

re: clean all

.PHONY: all clean re fclean move