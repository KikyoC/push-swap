/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:41:24 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/13 16:24:31 by togauthi         ###   ########.fr       */
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
int	cheapest(t_stack *main, t_stack *tmp, int stop)
{
	int	w1;
	int	w2;
	int w3;
	
	w1 = what_to_do(main, tmp);
	swap(main, NULL);
	w2 = what_to_do(main, tmp);
	swap(main, NULL);
	reverse_rotate(main, NULL);
	w3 = what_to_do(main, tmp);
	rotate(main, NULL);
	//ft_printf("%d %d %d\n", w1, w2 + 1, w3 + 1);
	if (w3 + 1 < w2 && w3 + 1 < w1 && stack_last(main)->nbr != stop)
	{
		//ft_printf("w3\n");
		reverse_rotate(main, "rra");
		return (w3);
	}
	if (w2 + 1 < w3 && w2 + 1 < w1 && main->top->next->nbr != stop)
	{
		//ft_printf("w3\n");
		swap(main, "sa");
		return (w2);
	}
	//ft_printf("w1\n");
	// (void)stop;
	return (w1);
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
		to_do = cheapest(main, tmp, stop);
		if (to_do > stack_len(tmp) / 2)
			to_do = to_do - stack_len(tmp);
		rotate_many(tmp, "rb", to_do);
		reverse_rotate_many(tmp, "rrb", to_do);
		push(main, tmp, "pb");
		if (tmp->top->nbr == lower(tmp))
			rotate(tmp, "rb");
	}
}
void	good_sort(t_stack *stack)
{
	int	big;

	big = bigger(stack);
	if (current_rank(stack, big) > stack_len(stack) / 2)
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
