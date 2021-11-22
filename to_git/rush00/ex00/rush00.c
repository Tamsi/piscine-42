/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschiffe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:04:32 by aschiffe          #+#    #+#             */
/*   Updated: 2021/09/11 14:39:39 by jhubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	display_form(char begend, char middle, int width)
{
	int	item;

	item = -1;
	while (++item < width)
	{
		if (item == 0 || item == (width - 1))
			ft_putchar(begend);
		else
			ft_putchar(middle);
	}
	write(1, "\n", 1);
}

void	rush(int width, int height)
{
	int	item;

	item = -1;
	if (width <= 0 || height <= 0)
		return ;
	while (++item < height)
	{
		if (item == 0 || item == (height - 1))
			display_form('o', '-', width);
		else
			display_form('|', ' ', width);
	}
}
