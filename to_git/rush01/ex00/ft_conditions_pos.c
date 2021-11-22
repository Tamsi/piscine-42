/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:04:41 by aguillar          #+#    #+#             */
/*   Updated: 2021/09/19 18:13:48 by aguillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_1_n_rank(int **tab, int col, int line, int val)
{
	if ((col == 1 && tab[line][0] == g_rank && val != 1) ||
			(col == 1 && tab[line][0] == 1 && val != g_rank) ||
			(col == g_rank && tab[line][g_rank + 1] == g_rank && val != 1) ||
			(col == g_rank && tab[line][g_rank + 1] == 1 && val != g_rank) ||
			(line == 1 && tab[0][col] == 1 && val != g_rank) ||
			(line == 1 && tab[0][col] == g_rank && val != 1) ||
			(line == g_rank && tab[g_rank + 1][col] == 1 && val != g_rank) ||
			(line == g_rank && tab[g_rank + 1][col] == g_rank && val != 1))
		return (0);
	return (1);
}
