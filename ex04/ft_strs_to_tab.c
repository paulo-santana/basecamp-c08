/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:35:40 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/16 22:31:15 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str++)
		counter++;
	return (counter);
}

char				*ft_strdup(char *str)
{
	int		i;
	int		length;
	char	*dup;

	length = ft_strlen(str);
	dup = malloc(sizeof(char) * length + 1);
	if (!dup)
		return (0);
	i = -1;
	while (++i < length)
		dup[i] = str[i];
	dup[i] = 0;
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			counter;
	t_stock_str	*tab;

	if (ac < 0)
		return (NULL);
	tab = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	counter = 0;
	while (counter < ac)
	{
		tab[counter].size = ft_strlen(av[counter]);
		tab[counter].copy = ft_strdup(av[counter]);
		if (tab[counter].copy == NULL)
			return (NULL);
		tab[counter].str = av[counter];
		counter++;
	}
	tab[counter].str = 0;
	tab[counter].copy = 0;
	tab[counter].size = 0;
	return (tab);
}
