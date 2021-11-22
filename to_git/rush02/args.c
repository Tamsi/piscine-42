#include "rush.h"

int		ft_check_num(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	if (count > 39)
		return (0);
	return (1);
}
