/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:21:42 by whumfrey          #+#    #+#             */
/*   Updated: 2019/02/26 19:56:16 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

static int	ft_sqrt(int number_tetrimino);
static int	ft_free_field(char **field);
static int	ft_print_field(char **field);
static char	*ft_read_map(char *argv);
static int	ft_number_tetrimino(char *map);
static char	**ft_card_split(char *map, int number_tetrimino);
static char	***ft_tetrimino(char *map, int number_tetrimino);
static int	ft_count_touch(char *map, int i);
static int	ft_chek_map(char *map);
static int	ft_chek_tetriminos(char **tetriminos, int number_tetrimino);
static int	ft_chek_point(char **tetriminos, int number_tetrimino);
static int	ft_chek(char **tetriminos, char *map, int number_tetrimino);
static char	**ft_creature_field(int m, int n);
static int	ft_clean_row_point(char ***matrix);
static int	ft_clean_column(char ***tetriminos, int k, int i, int j);
static int	ft_clean_column_point(char ***tetriminos);
static void	ft_to_alphabet(char ***tetriminos);
static int	ft_substitution_tetra(char **field, char **tetriminos, int x, int y);
static int	ft_chek_substitution(char **field, char **tetriminos, int x, int y);
static int	ft_clean_field(char **field, char **tetriminos, int x, int y);
static int	ft_solver(char **field, char ***tetriminos, int b);
static int	ft_solving(char ***tetriminos, int number_tetr);
static int	ft_sqrt(int number_tetrimino);
static int	ft_print_filed(char **field);

#endif
