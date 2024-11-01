/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:29:07 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/01 12:05:38 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	put_stack_end(t_stack *stack, t_element *element)
{
	t_element	*current;
	
	if (!stack->top)
	{
		stack->top = element;
		return ;
	}
	current = stack->top;
	while (current)
	{
		if (!current->next)
		{
			current->next = element;
			element->prev = current;
			break ;
		}
		current = current->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_element	*element;
	t_element	*next;
	
	element = stack->top;
	while (element)
	{
		next = element->next;
		free(element);
		element = next;
	}
	free(stack);
}