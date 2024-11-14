/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:48:21 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/14 11:47:57 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_args(int argc, char **argv)
{
	int		i;
	char	*c;
	char	**split;
	
	if (argc < 2)
		return (0);
	if (!argv[1][0])
		return (0);
	i = 0;
	split = ft_split(argv[1], ' ');
	while (split[i])
	{
		c = ft_itoa(ft_atoi(split[i]));
		if (ft_strncmp(c, split[i], ft_strlen(split[i])))
		{
			free(c);
			return (0);
		}
		free(c);
		i++;
	}
	return (1);
}
