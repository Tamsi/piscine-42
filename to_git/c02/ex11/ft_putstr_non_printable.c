/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:43:54 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/20 19:29:19 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	conv_char_to_hex(unsigned char c)
{
	unsigned char	div;
	unsigned char	mod;

	div = c / 16;
	mod = c % 16;
	ft_putchar('\\');
	if (div < 10)
		ft_putchar(div + '0');
	else
		ft_putchar(div + 'W');
	if (mod < 10)
		ft_putchar(mod + '0');
	else
		ft_putchar(mod + 'W');
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
			conv_char_to_hex((unsigned char)str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
