/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:28:49 by aguillar          #+#    #+#             */
/*   Updated: 2021/09/19 17:46:21 by aguillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	**ft_init_tab(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_rank + 2)
	{
		j = 0;
		while (j < g_rank + 2)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int	**ft_init_tab2(int **tab, char *str)
{
	int	mod;
	int	count;
	int	i;

	i = -1;
	count = 0;
	mod = 0;
	while (str[++i])
	{
		if (i % 2 == 0)
		{
			mod = ++count % g_rank;
			if (mod == 0)
				mod = g_rank;
			if ((count - 1) / g_rank == 0)
				tab[0][mod] = str[i] - '0';
			else if ((count - 1) / g_rank == 1)
				tab[g_rank + 1][mod] = str[i] - '0';
			else if ((count - 1) / g_rank == 2)
				tab[mod][0] = str[i] - '0';
			else if ((count - 1) / g_rank == 3)
				tab[mod][g_rank + 1] = str[i] - '0';
		}
	}
	return (tab);
}

int	**ft_malloc(char *str)
{
	int	i;
	int	**tab;

	i = 0;
	tab = malloc(sizeof(int *) * (g_rank + 2));
	if (!tab)
		return (NULL);
	while (i < (g_rank + 2))
	{
		tab[i] = malloc(sizeof(int) * (g_rank + 2));
		if (!tab[i])
			return (NULL);
		i++;
	}
	tab = ft_init_tab(tab);
	tab = ft_init_tab2(tab, str);
	return (tab);
}
