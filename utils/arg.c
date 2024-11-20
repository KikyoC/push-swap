/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:48:21 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/20 12:49:22 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_arg(char **splited)
{
	int		i;
	char	*c;

	i = 0;
	if (!splited)
		return (0);
	while (splited[i])
	{
		c = ft_itoa(ft_atoi(splited[i]));
		if (ft_strncmp(c, splited[i], ft_strlen(splited[i])))
		{
			free(c);
			free_split(splited);
			return (0);
		}
		free(c);
		i++;
	}
	free_split(splited);
	return (1);
}


int	check_args(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		return (1);
	if (!argv[1][0])
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!check_arg(ft_split(argv[i], ' ')))
			return (0);
		i++;
	}
	return (1);
}
