/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:08:01 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/15 14:08:03 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*res;

	res = dest;
	while (*res)
		res++;
	while (*src && nb > 0)
	{
		*res = *src;
		res++;
		src++;
		nb--;
	}
	*res = '\0';
	return (dest);
}
