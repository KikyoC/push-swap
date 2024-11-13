/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:27:41 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/13 16:43:11 by togauthi         ###   ########.fr       */
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

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}

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

char	*byte_to_char(int nbr)
{
	int		bytes;
	char	*res;
	int		i;
	
	bytes = how_many_bytes(nbr);
	res = ft_calloc(bytes + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < bytes - 1)
	{
		if (nbr >= ft_power(bytes - i - 1, 2))
		{
			nbr -= ft_power(bytes - i - 1, 2);
			res[i] = '1';
		}
		else
			res[i] = '0';
		i++;
	}
	if (nbr)
		res[i] = '1';
	else
		res[i] = '0';
	return (res);
}

void	radix(t_stack *main, t_stack *tmp)
{
	int			bits;
	int			actual;
	int			i;
	char		*actual_byte;
	
	bits = give_max_byte(main);
	actual = 0;
	while (actual < bits)
	{
		i = stack_len(main);
		while (--i)
		{
			actual_byte = byte_to_char(main->top->index);
			if (!actual_byte)
				exit(1);
			if (ft_strlen(actual_byte) > (size_t) actual && actual_byte[actual] == '1')
				rotate(main, "ra");
			else
				push(main, tmp, "pb");
			free(actual_byte);
		}
		while (tmp->top)
			push(tmp, main, "pa");
		actual ++;
	}
}


void	sort(t_stack *main, t_stack *tmp)
{
	set_index(main, stack_len(main));
	(void)tmp;
	radix(main, tmp);
}