/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:56:50 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/04 15:58:00 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	push_on_b(t_stack *main, t_stack *tmp)
{
	while (main->top && tmp->top && main->top->nbr > tmp->top->nbr)
	{
		push(main, tmp);
	}
	if (main->top && tmp->top)
		push(main, tmp);
}
void	push_on_a(t_stack *main, t_stack *tmp)
{
	if (stack_len(tmp) < 2)
		return ;
	if (stack_len(tmp) >= 2)
		swap(tmp);
	while (stack_len(tmp) >= 2 && tmp->top->next->nbr < tmp->top->nbr)
	{
		print_stack(tmp);
		printf("\nHello\n");
		push(tmp, main);
		swap(tmp);
	}
	swap(tmp);
}

void	sort(t_stack *main, t_stack *tmp)
{
	if (is_sorted(main) && stack_len(tmp) == 0)
		return ;
	push(main, tmp);
	push_on_b(main, tmp);
	push_on_a(main, tmp);
	sort(main, tmp);
}