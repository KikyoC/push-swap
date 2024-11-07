/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:56:34 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/07 14:53:49 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>


void	rotate(t_stack *stack)
{
	t_element	*top;
	t_element	*last;
	
	if (stack_len(stack) < 2)
		return ;
	top = stack->top;
	stack->top = top->next;
	last = stack_last(stack);
	last->next = top;
	top->prev = last;
	top->next = NULL;
}
