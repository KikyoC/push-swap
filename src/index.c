/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:56:50 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/07 16:43:22 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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

void	separate(t_stack *main, t_stack *tmp, int main_size)
{
	int	current_len;
	int	i;

	i = 0;
	current_len = 0;
	while (main_size > 6 && i < main_size && current_len < (main_size / 2))
	{
		if (main->top->index <= main_size / 2)
		{
			push(main, tmp);
			current_len++;
			printf("pb\n");
		}
		else
		{
			rotate(main);
			printf("ra\n");
		}
		i++;
	}
	main_size = stack_len(main);
	while (main_size > 3)
	{
		push(main, tmp);
		printf("pb\n");
		main_size --;		
	}
}

void	little_sort(t_stack *main)
{
	int			highest;
	t_element	*current;

	current = main->top;
	highest = 0;
	while (current)
	{
		if (current->index > highest)
			highest = current->index;
		current = current->next;
	} 
	if (stack_len(main) != 3 || is_sorted(main))
		return;
	if (highest == main->top->index)
	{
		rotate(main);
		printf("ra\n");
	}
	if (main->top->next->index < main->top->index)
	{
		swap(main);
		printf("sa\n");
	}
	if (main->top->index > main->top->next->next->index)
	{
		reverse_rotate(main);
		printf("rra\n");
	}
}

void	back(t_stack *main, t_stack *tmp)
{
	while (tmp->top)
	{
		push(tmp, main);
		printf("pa\n");	
		if (main->top->index + 1 != main->top->next->index)
		{
			rotate(main);
			printf("ra\n");
		}
		else
		{
			while (stack_last(main)->index + 1 == main->top->index)
			{
				reverse_rotate(main);
				printf("rra\n");
			}
			
		}
	}
}

void	sort(t_stack *main, t_stack *tmp)
{
	set_index(main, stack_len(main));
	// separate(main, tmp, stack_len(main));
	(void)tmp;
	little_sort(main);
	// back(main, tmp);
}
