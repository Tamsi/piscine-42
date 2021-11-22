#include "rush.h"

int		zero_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int		ft_more(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}
