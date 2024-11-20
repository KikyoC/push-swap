/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:48:21 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/20 14:16:09 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1[i] == '-' && s2[i] == '-')
		i++;
	else if (s1[i] == '-')
		j++;
	if (s1[i + j] == '+')
		j++;
	while (s1[i + j] == '0' && s1[i + j + 1])
		j++;
	while (((unsigned char)s1[i + j] != '\0'
			|| (unsigned char)s2[i] != '\0'))
	{
		if (s1[i + j] != s2[i])
		{
			return ((unsigned char)s1[i + j] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

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
		if (ft_strcmp(splited[i], c))
		{
			free(c);
			free_split(splited);
			return (0);
		}
		free(c);
		i++;
	}
	free_split(splited);
	return (i != 0);
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
