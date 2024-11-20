/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:08:26 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/20 13:06:39 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	include(t_stack *stack, int nbr)
{
	t_element	*current;

	current = stack->top;
	while (current)
	{
		if (current->nbr == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

int	create_elements(t_stack *stack, char **str)
{
	int			i;
	t_element	*element;

	i = 0;
	while (str[i])
	{
		element = ft_calloc(sizeof(t_element), 1);
		if (!element || include(stack, ft_atoi(str[i])))
		{
			if (element)
				free(element);
			free_stack(stack);
			free_split(str);
			return (0);
		}
		element->nbr = ft_atoi(str[i]);
		element->prev = NULL;
		element->next = NULL;
		element->index = 0;
		put_stack_end(stack, element);
		i++;
	}
	free_split(str);
	return (1);
}

t_stack	*create_stack(int argc, char **args)
{
	t_stack		*res;
	int			i;

	res = ft_calloc(sizeof(t_stack), 1);
	if (!res)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		if (!create_elements(res, ft_split(args[i], ' ')))
			return (NULL);
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_2;

	if (!check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack = create_stack(argc, argv);
	if (!stack)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_2 = ft_calloc(sizeof(t_stack), 1);
	if (!stack_2)
	{
		free_stack(stack);
		write(2, "Error\n", 6);
		return (1);
	}
	sort(stack, stack_2);
	free_stack(stack);
	free_stack(stack_2);
}
