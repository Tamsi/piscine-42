/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:24:40 by aguillar          #+#    #+#             */
/*   Updated: 2021/09/19 17:44:58 by aguillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_input(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if ((len == 0 || len > 71) || (str[len - 1] == ' ') || ((len + 1) % 8 != 0))
		return (0);
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '9'))
			return (0);
		if (i % 2 == 1 && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_nbrs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && str[i] > g_rank + 48)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	**tab;
	int	i;

	i = 0;
	if (ac == 2 && ft_check_input(av[1]))
	{
		g_rank = (ft_strlen(av[1]) + 1) / 8;
		if (!ft_check_nbrs(av[1]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		tab = ft_malloc(av[1]);
		if (!ft_rush(tab))
			write(1, "Error\n", 6);
		while (i < g_rank)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
