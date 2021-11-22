#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int		ft_more(char *str, int i);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		count_total(char *str);
int		ft_check_num(char *str);
char	**ft_parse_dict(void);
void	ft_print(char *str, char **tab);
char	*ft_rm_index(char *tab);
int		zero_check(char *str);

#endif
