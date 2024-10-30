/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:33:10 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/23 10:50:11 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>

int		ft_strlen(const char *str);
int		ft_putstr(const char *c);
int		ft_putchar(char c);
int		ft_putnbr_base(int n, char *base);
int		ft_putunbr(unsigned int nb);
int		ft_putunbr_base(unsigned int nb, char *base);
int		ft_print_mem(void *p);
#endif