/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:08:26 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/01 12:06:02 by togauthi         ###   ########.fr       */
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
	i = 1;
	while (i < argc)
	{
		element = ft_calloc(sizeof(t_element), 1);
		if (!element)
		{
			free_stack(res);
			exit(1);
		}
		element->nbr = ft_atoi(args[i]);
		element->prev = NULL;
		element->next = NULL;
		put_stack_end(res, element);
		i++;
	}
	return res;
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	
	if (!check_args(argc, argv))
		return (1);
	stack = create_stack(argc, argv);
	free_stack(stack);
}