/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:43:04 by tbesson           #+#    #+#             */
/*   Updated: 2021/09/26 18:43:13 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		count_total(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (str[i] == '0' && (!(str[i + 1] >= '0' && str[i + 1] <= '9')))
		return (0);
	while (str[i] != ':' && str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
			count = count + str[i];
		else if (str[i] == '0')
			count += 100;
		i++;
	}
	return (count);
}

int		ft_isspace(char *str)
{
	return (*str == '\n' || *str == '\f' || *str == '\r' || *str == '\v'
			|| *str == '\t' || *str == ' ');
}

char	*ft_rm_index(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != ':')
		i++;
	i++;
	while (ft_isspace(&tab[i]) == 1)
		i++;
	while (tab[i] != '\0')
	{
		if (!(ft_isspace(&tab[i]) && ft_isspace(&tab[i + 1])))
		{
			tab[j] = tab[i];
			tab[i] = ' ';
			j++;
		}
		i++;
	}
	tab[j - 1] = '\0';
	return (tab);
}

char	*ft_get_input(void)
{
	int		result;
	char	*buf;

	if (!(buf = malloc(sizeof(char*) * 100)))
		return (NULL);
	result = read(0, buf, 100);
	return (buf);
}

void	ft_free_memory(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
//#include <stdio.h>
int		main(int argc, char **argv)
{
	char	**tab;
	char	*num;

	if (argc > 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc == 2)
		num = argv[1];
	if (argc == 1)
	{
		num = ft_get_input();
		if (ft_strlen(num) > 1)
			num[ft_strlen(num) - 1] = '\0';
	}
	if (!ft_check_num(num))
	{
		ft_putstr("Error\n");
		return (0);
	}
	tab = ft_parse_dict();
	//for (int i = 0; tab[i]; i++)
		//printf("tab[%i] = %s\n", i, tab[i]);
	ft_print(num, tab);
	ft_free_memory(tab);
	return (0);
}
