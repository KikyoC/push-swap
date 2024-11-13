/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:53:23 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/13 10:58:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	what_to_do(t_stack *main, t_stack *tmp)
{
	t_element	*current;
	int			big;
	int			low;
	int 		moves;

	big = bigger(tmp);
	low = lower(tmp);
	moves = 0;
	current = tmp->top;
	if (main->top->nbr > big)
	{
		while (current->nbr != big)
		{
			current = current->next;
			moves ++;
		}
		return (moves);
	}
	if (main->top->nbr < low)
	{
		while (current->nbr != big)
		{
			current = current->next;
			moves ++;
		}
		return (moves);
	}
	while (current->nbr > main->top->nbr)
	{
		current = current->next;
		moves++;
		if (!current)
			return (0);
	}
	if (moves == 0)
	{
		current = stack_last(tmp);
		moves = stack_len(tmp);
		while (current->nbr < main->top->nbr)
		{
			if (!current)
				return (0);
			current = current->prev;
			moves --;
		}
	}
	return (moves);
}
