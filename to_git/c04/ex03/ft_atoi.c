/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:39:57 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/21 17:52:44 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 0;
	result = 0;
	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	while (*str && (*str == '-' || *str == '+'))
		if (*(str++) == '-')
			sign++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (sign > 0 && sign % 2 != 0)
		result = -result;
	return (result);
}
