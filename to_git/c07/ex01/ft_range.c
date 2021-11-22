/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:34:59 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/29 12:38:29 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
	{
		res = NULL;
		return (0);
	}
	res = malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
		res[i++] = min++;
	return (res);
}
