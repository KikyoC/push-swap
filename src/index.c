/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:13:46 by tom               #+#    #+#             */
/*   Updated: 2024/11/13 23:53:02 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	how_many_bytes(int i)
{
	int	res;
	int power;
	
	power = 1;
	res = 1;
	while (i > power)
	{
		power *= 2;
		res++;
	}
	if (res - 1 <= 0)
		return (1); 
	return (res - 1);
}


int	give_max_byte(t_stack *stack)
{
	t_element	*current;
	int			max;

	current = stack->top;
	max = 0;
	while (current)
	{
		if (how_many_bytes(current->index) > max)
			max = how_many_bytes(current->index);
		current = current->next;
	}
	return(max);
}
void	sort_tmp(t_stack *main, t_stack *tmp, int bit, int rank)
{
	int size;
	
	size = stack_len(tmp);
	
	while (size-- && rank < bit)
	{
		if (((tmp->top->nbr >> rank) & 1) == 0)
			rotate(tmp, "rb");
		else
			push(tmp, main, "pa");
	}
	if (is_sorted(main))
	{
		while (tmp->top)
			push(tmp, main, "pa");
	}
}

void	radix_sort(t_stack *main, t_stack *tmp)
{
    int	j;
    int	bit;
    int	size;

    j = -1;
	bit = 0;
	size = stack_len(main);
	while (size > 1 && ++bit)
		size /= 2;
    while (++j <= bit)
    {
		size = stack_len(main);
		while (size-- && !is_sorted(main))
		{
			if (((main->top->nbr >> j) & 1) == 0)
				push(main, tmp, "pb");
			else
				rotate(main, "ra");
		}
		sort_tmp(main, tmp, bit, j);
    }
	while (tmp->top)
		push(tmp, main, "pa");
}


void	sort(t_stack *main, t_stack *tmp)
{
	radix_sort(main, tmp);
}
