# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 11:06:49 by togauthi          #+#    #+#              #
#    Updated: 2024/11/04 14:39:12 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF = libftprintf.a
LIBFT = libft.a
CFLAGS = -Wall -Werror -Wextra -g
SRCS = push_swap.c \
	utils/arg.c \
	utils/stack.c \
	utils/push.c \
	utils/swap.c \
	utils/print.c \
	utils/rotate.c \
	utils/reverse_rotate.c \

GREEN = \e[0;32m
WHITE = \e[0;37m
AQUA = \e[0;36m
YELLOW = \e[0;33m

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF):
	@echo "$(YELLOW)Compiling printf... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)3$(WHITE)]" 
	@make --no-print-directory -C printf
	@mv printf/libftprintf.a ./

$(LIBFT):
	@echo "$(YELLOW)Compiling libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)3$(WHITE)]" 
	@make --no-print-directory -C libft
	@mv libft/libft.a ./

$(NAME): $(PRINTF) $(LIBFT) $(OBJS)
	@echo "$(YELLOW)Compiling push_swap... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@cc $(CFLAGS) -o $@ $(OBJS) $(PRINTF) $(LIBFT)
	@echo "$(GREEN)Done."
%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Clearing printf... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)3$(WHITE)]"
	@make --no-print-directory -C printf clean
	@rm -f $(PRINTF)
	@echo "$(YELLOW)Clearing libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)3$(WHITE)]"
	@make --no-print-directory -C libft clean
	@rm -f $(LIBFT)
	@echo "$(YELLOW)Clearing objects... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@rm -f $(OBJS)
	@echo "$(GREEN)Done."

fclean: clean
	@echo "$(YELLOW)Clearing result...$(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)1$(WHITE)]"
	@rm -f $(NAME)
	@echo "$(GREEN)Done."

re: fclean all

.PHONY: all clean fclean re