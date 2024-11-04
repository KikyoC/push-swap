/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:09:04 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/04 15:36:42 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_element
{
	int					nbr;
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
void		swap(t_stack *stack);
void		push(t_stack *original, t_stack *to_push);
void		rotate(t_stack *stack);
t_element	*element_copy(t_element *element);
size_t		stack_len(t_stack *stack);
t_element	*stack_last(t_stack *stack);
int			is_sorted(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		sort(t_stack *main, t_stack *tmp);

#endif