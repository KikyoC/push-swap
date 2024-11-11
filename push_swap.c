/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:08:26 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/11 17:29:41 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack *create_stack(int argc, char **args)
{
	t_stack		*res;
	t_element	*element;
	int			i;
	
	res = ft_calloc(sizeof(t_stack), 1);
	if (!res)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		element = ft_calloc(sizeof(t_element), 1);
		if (!element)
		{
			free_stack(res);
			return (NULL);
		}
		element->nbr = ft_atoi(args[i]);
		element->prev = NULL;
		element->next = NULL;
		element->index = 0;
		put_stack_end(res, element);
		i++;
	}
	return res;
}

void print_index(t_stack *stack)
{
	t_element	*current;

	current = stack->top;
	while (current)
	{
		printf("Number:%d --> %d\n", current->nbr, current->index);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_2;
	
	if (!check_args(argc, argv))
		return (1);
	stack = create_stack(argc, argv);
	if (!stack)
		return (1);
	stack_2 = ft_calloc(sizeof(t_stack), 1);
	if (!stack_2)
	{
		free_stack(stack);
		return (1);
	}
	sort(stack, stack_2);
}