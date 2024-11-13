/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:09:04 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/13 16:24:41 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_element
{
	int					nbr;
	int					index;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_stack
{
	t_element	*top;
}	t_stack;

int			check_args(int argc, char **argv);
void		put_stack_end(t_stack *stack, t_element *element);
void		free_stack(t_stack *stack);
void		print_stack(t_stack *stack);
void		swap(t_stack *stack, char *to_print);
void		push(t_stack *original, t_stack *to_push, char *to_print);
void		rotate(t_stack *stack, char *to_print);
t_element	*element_copy(t_element *element);
int			stack_len(t_stack *stack);
t_element	*stack_last(t_stack *stack);
int			is_sorted(t_stack *stack);
void		reverse_rotate(t_stack *stack, char *to_print);
void		sort(t_stack *main, t_stack *tmp);
int			current_rank(t_stack *stack, int i);
int			what_to_do(t_stack *main, t_stack *tmp);
void		set_index(t_stack *stack, int size);
void		rotate_many(t_stack *stack, char *to_print, int times);
void		reverse_rotate_many(t_stack *stack, char *to_print, int times);
#endif