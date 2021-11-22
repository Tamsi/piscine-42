/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:15:02 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/09 12:15:05 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	my_nb[2];

	my_nb[0] = (nb / 10) + '0';
	my_nb[1] = (nb % 10) + '0';
	write(1, &my_nb, 2);
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_putnbr(a);
			write(1, " ", 1);
			ft_putnbr(b++);
			if (a < 98 || b < 99)
				write(1, ", ", 2);
		}
		a++;
	}
}
