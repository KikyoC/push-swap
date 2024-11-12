/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:41:24 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/12 17:13:04 by togauthi         ###   ########.fr       */
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

	low = INT_MAX;
	current = stack->top;
	while (current)
	{
		if (current->nbr < low)
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
	// ft_printf("end of function\n");
	return (moves);
}
void	push_tmp(t_stack *main, t_stack *tmp, int stop)
{
	int	big;
	int low;
	int	to_do;
	
	big = bigger(tmp);
	low = lower(tmp);
	while (main->top->next)
	{
		if (main->top->nbr == stop)
		{
			rotate(main, "ra");
			continue ;
		}
		to_do = what_to_do(main, tmp);
		// ft_printf("**%d**\n", to_do);
		while (to_do > 0)
		{
			rotate(tmp, "rb");
			to_do --;
		}
		push(main, tmp, "pb");
		if (tmp->top->nbr == lower(tmp))
			rotate(tmp, "rb");
	}
}
void	good_sort(t_stack *stack)
{
	int	big;

	big = bigger(stack);
	if (current_rank(stack, big) < stack_len(stack) / 2)
	{
		while (stack->top->nbr != big)
			reverse_rotate(stack, "rrb");
		return ;
	}
	while (stack->top->nbr != big)
		rotate(stack, "rb");
}

void	sort(t_stack *main, t_stack *tmp)
{
	int	stop;

	stop = bigger(main);
	set_index(main, stack_len(main));
	if (main->top->nbr == stop)
		rotate(main, "ra");
	push(main, tmp, "pb");
	if (main->top->nbr == stop)
		rotate(main, "ra");
	push(main, tmp, "pb");
	if (is_sorted(tmp))
		rotate(tmp, "rb");
	push_tmp(main, tmp, stop);
	good_sort(tmp);
	while (tmp->top)
		push(tmp, main, "pa");

}