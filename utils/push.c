/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:22:48 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/04 12:38:36 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *original, t_stack *to_push)
{
	t_element	*top;
	t_element	*next;
	
	if (stack_len(original) < 1)
		return ;
	top = original->top;
	original->top = original->top->next;
	next = to_push->top;
	top->prev = NULL;
	top->next = next;
	to_push->top = top;
}
