/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:44:02 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/29 20:44:46 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_base_position(char c, char *base);
int		ft_check_base(char *base);
void	ft_rev_tab(char *tab, int size);

long int	ft_atoi_base(char *str, char *base)
{
	long int	i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	if (ft_check_base(base) == 0)
		return (0);
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_base_position(str[i], base) >= 0)
	{
		res = (res * ft_strlen(base)) + (ft_base_position(str[i], base));
		i++;
	}
	return (res * sign);
}

long int	ft_fill_tab(char *tab, long int num, char *base_to)
{
	int			negative;
	int			base_len;
	long int	i;

	base_len = ft_strlen(base_to);
	negative = 0;
	i = 0;
	if (num < 0)
	{
		negative = 1;
		num = -num;
	}
	if (num == 0)
	{
		tab[i++] = base_to[num % base_len];
	}
	while (num)
	{
		tab[i++] = base_to[num % base_len];
		num = num / base_len;
	}
	if (negative)
		tab[i++] = '-';
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	num;
	int			i;
	char		*tab;

	i = 0;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	tab = malloc(sizeof(char) * 40);
	if (tab == NULL)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	i = ft_fill_tab(tab, num, base_to);
	ft_rev_tab(tab, i);
	tab[i] = '\0';
	return (tab);
}
