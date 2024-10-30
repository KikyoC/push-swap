/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:48:21 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/30 10:56:40 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i > argc)
	{
		if (ft_itoa(ft_atoi(argv[i])) != argv[i])
			return (0);
	}
	return (1);
}