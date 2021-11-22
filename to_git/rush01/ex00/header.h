/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:23:20 by aguillar          #+#    #+#             */
/*   Updated: 2021/09/19 22:39:26 by aguillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

int		g_rank;

int		ft_is_valid_col(int **tab, int line, int val);
int		ft_is_valid_revcol(int **tab, int line, int val);
int		ft_cond_col(int **tab, int col);
int		ft_cond_revcol(int **tab, int col);
int		ft_cond_line(int **tab, int line);
int		ft_cond_revline(int **tab, int line);
int		ft_check_1_n_rank(int **tab, int col, int line, int val);
void	ft_print_tab(int **tab);
int		ft_grid_is_ok(int **tab);
int		ft_is_valid_pos(int **tab, int col, int line, int val);
void	ft_recursive(int **tab, int col, int line, int *i);
int		ft_rush(int **tab);
int		**ft_init_tab(int **tab);
int		**ft_init_tab2(int **tab, char *str);
int		**ft_malloc(char *str);

#endif
