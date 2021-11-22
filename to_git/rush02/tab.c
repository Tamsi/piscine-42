#include "rush.h"

void	ft_sort_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (count_total(tab[i]) > count_total(tab[j]))
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int		count_lines(int fd)
{
	int		count;
	char	buf[2];
	int		ret;

	count = 0;
	while ((ret = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			count++;
	}
	return (count);
}

void	ft_malloc_tab(char **tab, int fd)
{
	int		i;
	int		count;
	char	buf[2];
	int		ret;

	i = 0;
	count = 0;
	while ((ret = read(fd, buf, 1)))
	{
		i++;
		if (buf[0] == '\n')
		{
			if (!(tab[count] = malloc(sizeof(char*) * (i + 1))))
				return ;
			i = 0;
			count++;
		}
	}
	tab[count] = NULL;
}

void	ft_fill_tab(char **tab, int fd)
{
	int		i;
	int		count;
	char	buf[2];
	int		res;

	i = 0;
	count = 0;
	while ((res = read(fd, buf, 1)))
	{
		tab[count][i] = buf[0];
		tab[count][i + 1] = '\0';
		i++;
		if (buf[0] == '\n')
		{
			i = 0;
			count++;
		}
	}
	tab[count] = NULL;
}

char	**ft_parse_dict(void)
{
	char	**tab;
	int		fd;
	int		i;

	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
		return (NULL);
	tab = malloc(sizeof(char*) * (count_lines(fd) + 1));
	if (close(fd) == -1)
		return (NULL);
	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
		return (tab);
	ft_malloc_tab(tab, fd);
	if (close(fd) == -1)
		return (NULL);
	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
		return (tab);
	ft_fill_tab(tab, fd);
	ft_sort_tab(tab);
	if (close(fd) == -1)
		return (NULL);
	i = -1;
	while (tab[++i])
		ft_rm_index(tab[i]);
	return (tab);
}
