/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:04:09 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/11 18:04:12 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	y;

	i = 0;
	while (i < size - 1)
	{
		y = 0;
		while (y < size - i - 1)
		{
			if (tab[y] > tab[y + 1])
				ft_swap(&tab[y], &tab[y + 1]);
			y++;
		}
		i++;
	}
}
