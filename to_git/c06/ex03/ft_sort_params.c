/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:56:21 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/27 19:51:57 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2);

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_sort_p_tab(char **tab, int size)
{
	int		i;
	int		y;
	char	*tmp;

	i = 1;
	while (i < size)
	{
		y = i + 1;
		while (y < size)
		{
			if (ft_strcmp(tab[y], tab[i]) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[y];
				tab[y] = tmp;
			}
			y++;
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac > 1)
	{
		i = 0;
		ft_sort_p_tab(av, ac);
		while (av[++i])
			ft_putstr(av[i]);
	}
	return (0);
}
