/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:28:10 by aguillar          #+#    #+#             */
/*   Updated: 2021/09/19 22:40:10 by aguillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_tab(int **tab)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i <= g_rank)
	{
		j = 1;
		while (j <= g_rank)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (j < g_rank)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_grid_is_ok(int **tab)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while (i <= g_rank)
	{
		if (!ft_cond_col(tab, i) || !ft_cond_revcol(tab, i))
			return (0);
		i++;
	}
	while (j <= g_rank)
	{
		if (!ft_cond_line(tab, j) || !ft_cond_revline(tab, j))
			return (0);
		j++;
	}
	return (1);
}

int	ft_is_valid_pos(int **tab, int col, int line, int val)
{
	int	i;
	int	j;

	i = 1;
	while (i <= line)
	{
		j = 1;
		while (j <= col)
		{
			if (tab[i][j] == val && j == col && i != line)
				return (0);
			else if (tab[i][j] == val && i == line && j != col)
				return (0);
			j++;
		}
		i++;
	}
	if (!ft_check_1_n_rank(tab, col, line, val))
		return (0);
	return (1);
}

void	ft_recursive(int **tab, int col, int line, int *i)
{
	int	val;

	val = 1;
	while (val <= g_rank)
	{
		if (ft_is_valid_pos(tab, col, line, val))
		{
			tab[line][col] = val;
			if (col < g_rank)
				ft_recursive(tab, col + 1, line, i);
			else if (line < g_rank)
				ft_recursive(tab, 1, line + 1, i);
			else if (ft_grid_is_ok(tab))
			{
				ft_print_tab(tab);
				*i = 42;
			}
		}
		val++;
	}
}

int	ft_rush(int **tab)
{
	int	col;
	int	line;
	int	i;

	col = 1;
	line = 1;
	i = 0;
	ft_recursive(tab, col, line, &i);
	if (i == 42)
		return (1);
	return (0);
}
