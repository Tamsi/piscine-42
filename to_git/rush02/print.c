#include "rush.h"

int		ft_print_hundred(char *str, char **tab, int i, int len)
{
	ft_putstr(tab[str[i] - '0']);
	ft_putstr(" ");
	ft_putstr(tab[28]);
	if ((str[i + 1] == '0' && str[i + 2] == '0') && (len > 3))
	{
		ft_putstr(" ");
		ft_putstr(tab[27 + (len / 3)]);
		return (0);
	}
	if (ft_more(str, i + 1))
		return (0);
	return (1);
}

int		ft_print_tens(char *str, char **tab, int i, int len)
{
	if (str[i] == '1' && str[i + 1] != '0')
	{
		ft_putstr(tab[(str[i + 1] - '0' + 9)]);
		if (len > 3)
		{
			ft_putstr(" ");
			ft_putstr(tab[28 + (len / 3)]);
			if (ft_more(str, i + 2))
				ft_putstr(" ");
		}
		return (1);
	}
	else
		ft_putstr(tab[(str[i] - '0') + 18]);
	if ((str[i + 1] == '0') && (len > 3))
	{
		ft_putstr(" ");
		ft_putstr(tab[28 + (len / 3)]);
	}
	if (ft_more(str, i + 1))
		return (0);
	return (1);
}

int		ft_print_units(char *str, char **tab, int i, int len)
{
	if (i == 0 && len == 1)
	{
		ft_putstr(tab[str[i] - '0']);
		return (1);
	}
	if (len > 3 && str[i - 1] != '1')
	{
		ft_putstr(tab[str[i] - '0']);
		ft_putstr(" ");
		ft_putstr(tab[28 + (len / 3)]);
		if (ft_more(str, i + 1))
			return (0);
		return (1);
	}
	else if (str[i - 1] != '1')
		ft_putstr(tab[str[i] - '0']);
	if (ft_more(str, i + 1) && str[i - 1] != '1')
		return (0);
	return (1);
}

void	ft_print(char *str, char **tab)
{
	int		i;
	int		len;
	int		can;

	len = ft_strlen(str);
	i = 0;
	if (zero_check(str))
		ft_putstr(tab[str[i] - '0']);
	while (len > 0)
	{
		if (str[i] - '0' != 0)
		{
			if (len % 3 == 0)
				can = ft_print_hundred(str, tab, i, len);
			else if (len % 3 == 2)
				can = ft_print_tens(str, tab, i, len);
			else
				can = ft_print_units(str, tab, i, len);
			if (can != 1 && len > 1 && ft_more(str, i + 1))
				ft_putstr(" ");
		}
		i++;
		len--;
	}
	write(1, "\n", 1);
}
