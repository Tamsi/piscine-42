/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:28:36 by aguillar          #+#    #+#             */
/*   Updated: 2021/09/19 18:11:45 by aguillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_cond_col(int **tab, int line)
{
	int	i;
	int	max;
	int	compt;

	i = 1;
	max = tab[line][1];
	compt = 1;
	while (i <= g_rank)
	{
		if (max < tab[line][i])
		{
			max = tab[line][i];
			compt++;
		}
		i++;
	}
	if (compt != tab[line][0])
		return (0);
	return (1);
}

int	ft_cond_revcol(int **tab, int line)
{
	int	i;
	int	max;
	int	compt;

	i = g_rank;
	max = tab[line][g_rank];
	compt = 1;
	while (i > 0)
	{
		if (max < tab[line][i])
		{
			max = tab[line][i];
			compt++;
		}
		i--;
	}
	if (compt != tab[line][g_rank + 1])
		return (0);
	return (1);
}

int	ft_cond_line(int **tab, int col)
{
	int	i;
	int	max;
	int	compt;

	i = 1;
	max = tab[1][col];
	compt = 1;
	while (i <= g_rank)
	{
		if (max < tab[i][col])
		{
			max = tab[i][col];
			compt++;
		}
		i++;
	}
	if (compt != tab[0][col])
		return (0);
	return (1);
}

int	ft_cond_revline(int **tab, int col)
{
	int	i;
	int	max;
	int	compt;

	i = g_rank;
	max = tab[g_rank][col];
	compt = 1;
	while (i > 0)
	{
		if (max < tab[i][col])
		{
			max = tab[i][col];
			compt++;
		}
		i--;
	}
	if (compt != tab[g_rank + 1][col])
		return (0);
	return (1);
}
