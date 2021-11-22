/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:51:35 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/30 17:08:38 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * len + 1);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*strustr;
	int			i;

	strustr = malloc((ac + 1) * sizeof(t_stock_str));
	if (strustr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		strustr[i].size = fr_strlen(av[i]);
		strustr[i].str = av[i];
		strustr[i].copy = ft_strdup(av[i]);
		i++;
	}
	strustr[i] = NULL;
	return (strustr);
}
