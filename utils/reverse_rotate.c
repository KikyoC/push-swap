/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:35:18 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/11 16:02:00 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack *stack, char *to_print)
{
	t_element	*top;
	t_element	*last;
		
	if (stack_len(stack) < 2)
		return ;
	top = stack->top;
	if (stack_len(stack) == 2)
	{
		last = top->next;
		top->prev = last;
		last->next = top;
	}
	else
	{
		last = stack_last(stack);
		last->next = top;
		top->prev = last;
	}
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	stack->top = last;
	if (to_print)
		ft_printf("%s\n", to_print);
}
