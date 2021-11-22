/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:47:27 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/14 10:47:30 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	write_hex_char(char c)
{
	char	div;
	char	mod;

	div = c / 16;
	mod = c % 16;
	if (div < 10)
		div += '0';
	else
		div += 'W';
	if (mod < 10)
		mod += '0';
	else
		mod += 'W';
	write(1, &div, 1);
	write(1, &mod, 1);
}

void	ft_putstr_hex(char *str)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		if (i >= 0 && i % 2 == 0)
			write(1, " ", 1);
		write_hex_char(*str);
		if (*str == '\0')
			break ;
		str++;
	}
	while (++i < 16)
		write(1, " ", 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (*str < 32 || *str == 127)
			write(1, ".", 1);
		else
			write(1, str, 1);
		if (*str == '\0')
			break ;
		str++;
		i++;
	}
	write(1, "\n", 1);
}

void	write_ptr(void *p)
{
	uint32_t	addr_p;
	char		buf[16];
	char		*base;
	int			i;

	addr_p = (uint32_t)p;
	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		buf[i] = base[(addr_p >> ((15 - i) * 4)) & 0xF];
		i++;
	}
	buf[i] = '\0';
	write(1, buf, sizeof(buf));
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0 || i % 16 == 0)
		{
			write_ptr(addr);
			ft_putstr_hex(addr);
			write(1, " ", 1);
			ft_putstr_non_printable(addr);
		}
		addr++;
		i++;
	}
	return (addr);
}
