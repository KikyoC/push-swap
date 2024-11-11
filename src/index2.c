/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:41:24 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/11 16:16:15 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_stack *stack, int size)
{
	t_element	*current;
	t_element	*hight;
	int 		last;
	
	while (--size)
	{
		current = stack->top;
		last = -2147483648;
		while (current)
		{
			if (current->nbr == -2147483648 && !current->index)
				current->index = 1;
			if (current->nbr > last && !current->index)
			{
				last = current->nbr;
				hight = current;
				current = stack->top;
			}
			else
				current = current->next;
		}
		if (hight)
			hight->index = size;
	}
}

int	bigger(t_stack *stack)
{
	int 		big;
	t_element	*current;

	big = INT_MIN;
	current = stack->top;
	while (current)
	{
		if (current->nbr > big)
			big = current->nbr;
		current = current->next;
	}
	return (big);
}


int lower(t_stack *stack)
{
	int 		low;
	t_element	*current;

	low = INT_MIN;
	current = stack->top;
	while (current)
	{
		if (current->nbr > low)
			low = current->nbr;
		current = current->next;
	}
	return (low);
}
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
		if (moves > stack_len(tmp) / 2)
			return (-moves);
		return (moves);
	}
	if (main->top->nbr < low)
	{
		while (current->nbr != low)
		{
			current = current->next;
			moves ++;
		}
		moves ++;
		if (moves > stack_len(tmp) / 2)
			return (-moves);
		return (moves);
	}
	if (main->top->nbr < tmp->top->index && main->top->nbr > stack_last(tmp)->nbr)
		return (0);
	while (current->next && !(current->nbr < main->top->nbr && current->next->nbr > main->top->nbr))
	{
		current = current->next;
		moves ++;
	}
	if (moves > stack_len(tmp) / 2)
		return (-moves);
	return (moves);
}
void	push_tmp(t_stack *main, t_stack *tmp)
{
	int	size;
	int	big;
	int low;
	int	to_do;
	
	size = stack_len(main);
	big = bigger(tmp);
	low = lower(tmp);
	while (size > 3)
	{
		to_do = what_to_do(main, tmp);
		while (to_do > 0)
		{
			rotate(tmp, "rb");
			to_do --;
		}
		while (to_do < 0)
		{
			reverse_rotate(tmp, "rrb");
			to_do ++;
		}
		push(main, tmp, "pb");
		size--;
	}
}


void	sort(t_stack *main, t_stack *tmp)
{
	set_index(main, stack_len(main));
	push(main, tmp, "pb");
	push(main, tmp, "pb");
	push_tmp(main, tmp);	
}