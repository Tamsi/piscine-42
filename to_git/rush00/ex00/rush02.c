/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:35:03 by jhubert           #+#    #+#             */
/*   Updated: 2021/09/11 14:45:47 by jhubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	display_square(int i, int y, int width, int height)
{
	if ((i == 0 && y == 0) || (i == 0 && y == width - 1))
		ft_putchar('A');
	else if (i == height - 1 && (y == 0 || y == width - 1))
		ft_putchar('C');
	else if ((i == 0 || i == height - 1) || (y == 0 || y == width - 1))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int width, int height)
{
	int	i;
	int	y;

	i = 0;
	if (width <= 0 || height <= 0)
		return ;
	while (i < height)
	{
		y = 0;
		while (y < width)
		{
			display_square(i, y, width, height);
			y++;
		}
		ft_putchar('\n');
		i++;
	}
}
