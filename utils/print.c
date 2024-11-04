/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:12:36 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/04 13:58:19 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_element	*current;
	
	current = stack->top;
	while (current)
	{
		ft_printf("%d\n", current->nbr);
		current = current->next;
	}
}
