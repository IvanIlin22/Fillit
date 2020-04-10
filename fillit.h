/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:21:42 by whumfrey          #+#    #+#             */
/*   Updated: 2019/02/26 21:01:44 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_SIZE 21

int		ft_sqrt(int number_tetrimino);
int		ft_free_field(char **field);
int		ft_print_field(char **field);
char	*ft_read_map(char *argv);
int		ft_number_tetrimino(char *map);
char	**ft_card_split(char *map, int number_tetrimino);
char	***ft_tetrimino(char *map, int number_tetrimino);
int		ft_count_touch(char *map, int i);
int		ft_chek_map(char *map);
int		ft_chek_tetriminos(char **tetriminos, int number_tetrimino);
int		ft_chek_point(char **tetriminos, int number_tetrimino);
int		ft_chek(char **tetriminos, char *map, int number_tetrimino);
char	**ft_creature_field(int m, int n);
int		ft_clean_row_point(char ***matrix);
int		ft_clean_column(char ***tetriminos, int k, int i, int j);
int		ft_clean_column_point(char ***tetriminos);
void	ft_to_alphabet(char ***tetriminos);
int		ft_substitution_tetra(char **field, char **tetriminos, int x, int y);
int		ft_chek_substitution(char **field, char **tetriminos, int x, int y);
int		ft_clean_field(char **field, char **tetriminos, int x, int y);
int		ft_solver(char **field, char ***tetriminos, int b);
int		ft_solving(char ***tetriminos, int number_tetr);
int		ft_sqrt(int number_tetrimino);
int		ft_print_filed(char **field);

#endif
