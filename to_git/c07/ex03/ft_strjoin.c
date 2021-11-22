/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:34:16 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/29 20:42:27 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_term_size(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total = total + ft_strlen(strs[i]);
		i++;
	}
	if (!size)
		return (0);
	total = total + ft_strlen(sep) * (size - 1) + 1;
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		str_len;
	char	*final_str;

	i = 0;
	if (size == 0)
	{
		final_str = malloc(sizeof(char));
		final_str[0] = '\0';
		return (final_str);
	}
	str_len = ft_term_size(size, strs, sep);
	final_str = malloc(sizeof(char) * str_len + 1);
	if (final_str == NULL)
		return (NULL);
	final_str[0] = '\0';
	while (i < size)
	{
		ft_strcat(final_str, strs[i]);
		if (i < size - 1)
			ft_strcat(final_str, sep);
		i++;
	}
	return (final_str);
}
