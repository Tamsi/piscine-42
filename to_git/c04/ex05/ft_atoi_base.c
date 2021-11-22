/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:40:23 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/21 17:22:36 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = -1;
		while (base[++j])
			if (base[i] == base[j] && j != i)
				return (0);
		i++;
	}
	return (1);
}

int	is_in_base(char *base, char nb)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (nb == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	nb_base;

	sign = 0;
	result = 0;
	if (!control_base(base))
		return (0);
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	while (*str && (*str == '-' || *str == '+'))
		if (*(str++) == '-')
			sign++;
	while (is_in_base(base, *str) >= 0)
	{
		nb_base = is_in_base(base, *str);
		result = result * ft_strlen(base) + nb_base;
		str++;
	}
	if (sign > 0 && sign % 2 != 0)
		result = -result;
	return (result);
}
