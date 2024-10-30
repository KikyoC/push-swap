# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 11:06:49 by togauthi          #+#    #+#              #
#    Updated: 2024/10/30 11:26:40 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

PRINTF = libftprintf.a
LIBFT = libft.a

all: $(PRINTF) $(LIBFT)

$(PRINTF):
	make -C printf
	mv printf/libftprintf.a ./

$(LIBFT):
	make -C libft
	mv libft/libft.a ./

clean:
	make -C printf clean
	make -C libft clean
	rm -f $(PRINTF) $(LIBFT)


.PHONY: all clean