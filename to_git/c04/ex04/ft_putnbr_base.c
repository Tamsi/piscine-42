/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:40:10 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/23 20:50:05 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	control_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = -1;
		while (base[++j])
			if (base[i] == base[j] && j != i)
				return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	my_nb;
	unsigned int	base_len;

	my_nb = nb;
	base_len = ft_strlen(base);
	if (control_base(base) == 0)
		return ;
	if (nb < 0)
	{
		my_nb = -nb;
		write(1, "-", 1);
	}
	if (my_nb > base_len - 1)
		ft_putnbr_base(my_nb / base_len, base);
	ft_putchar(base[my_nb % base_len]);
}
