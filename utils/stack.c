/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:29:07 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/12 11:02:29 by togauthi         ###   ########.fr       */
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

t_element	*element_copy(t_element *element)
{
	t_element	*res;

	res = ft_calloc(sizeof(t_element), 1);
	if (!res)
		return (NULL);
	res->prev = NULL;
	res->next = NULL;
	res->nbr = element->nbr;
	return (res);
}

int	stack_len(t_stack *stack)
{
	t_element	*current;
	int		i;
	
	current = stack->top;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);	
}

t_element	*stack_last(t_stack *stack)
{
	t_element	*current;
	
	current = stack->top;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

int current_rank(t_stack *stack, int index)
{
	t_element	*current;
	int			i;
	
	i = 0;
	current = stack->top;
	while (current)
	{
		if (current->index == index)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}