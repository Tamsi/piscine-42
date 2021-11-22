/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:06:03 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/10 10:09:42 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_str_display(char *str, int i, int n)
{
	int	y;

	y = 0;
	while (str[y])
		write(1, &str[y++], 1);
}

void	print_combn_1(int i, int n, char *my_nb)
{
	while (my_nb[i] <= '9')
	{
		ft_str_display(my_nb, i, n);
		if (my_nb[i] < '9')
			write(1, ", ", 2);
		my_nb[i]++;
	}
}

void	print_combn(int i, int n, char *my_nb)
{
	while (i >= 0)
	{
		if (i == n - 1)
		{
			while (my_nb[i] <= '9')
			{
				ft_str_display(my_nb, i, n);
				write(1, ", ", 2);
				if (my_nb[i] == '9')
					break ;
				my_nb[i]++;
			}
		}
		else
		{
			while (my_nb[i] < my_nb[i + 1] - 1)
			{
				my_nb[i]++;
				ft_str_display(my_nb, i, n);
				if (i > 0 || my_nb[i] < my_nb[i + 1] - 1)
					write(1, ", ", 2);
			}
		}
		i--;
	}
}

void	ft_print_combn(int n)
{
	char	my_nb[10];
	int		i;

	if (n < 0 && n > 10)
		return ;
	i = 0;
	my_nb[i] = '0';
	while (i < n)
		my_nb[i] = my_nb[i++] + 1;
	my_nb[i] = '\0';
	i = n - 1;
	if (n > 1)
		print_combn(i, n, my_nb);
	else
		print_combn_1(i, n, my_nb);
}
