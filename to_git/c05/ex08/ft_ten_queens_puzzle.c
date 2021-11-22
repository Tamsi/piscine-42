/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:51 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/20 23:29:04 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_count;

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_diff_abs(int i, int line)
{
	if (i <= line)
		return (line - i);
	else
		return (i - line);
}

int	ft_is_valid_pos(char *dames, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		if (dames[line] == dames[i]
			|| ft_diff_abs(dames[i], dames[line]) == line - i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_recursive(char *dames, int line)
{	
	dames[line] = '0';
	while (dames[line] <= '9')
	{
		if (ft_is_valid_pos(dames, line))
		{
			if (line == 9)
			{
				if (dames[9] >= '0' && dames[9] <= '9')
				{
					g_count++;
					ft_putstr(dames);
				}
			}
			else
				ft_recursive(dames, line + 1);
		}
		dames[line]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	dames[10];
	int		line;

	line = 0;
	g_count = 0;
	ft_recursive(dames, line);
	return (g_count);
}
