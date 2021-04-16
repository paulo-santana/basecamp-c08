/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:04:53 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/16 23:06:04 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putnbr(int nb)
{
	int		length;
	int		is_min;
	char	str[10];

	is_min = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			is_min = 1;
			nb++;
		}
		nb = -nb;
	}
	length = 0;
	while (nb != 0 || length < 1)
	{
		str[length] = nb % 10 + is_min + '0';
		is_min = 0;
		nb = nb / 10;
		length++;
	}
	while (--length >= 0)
		write(1, &str[length], 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_tab(t_stock_str tab)
{
	ft_putstr(tab.str);
	ft_putstr("\n");
	ft_putnbr(tab.size);
	ft_putstr("\n");
	ft_putstr(tab.copy);
	ft_putstr("\n");
}

void	ft_show_tab(t_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		print_tab(par[i]);
	}
}
