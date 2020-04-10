/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:52:35 by whumfrey          #+#    #+#             */
/*   Updated: 2019/02/26 18:21:07 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argv, char **argc)
{
	char	*map;
	char	**val_tetr;
	char	***tetriminos;
	int		number_tetr;
	int		min;

	number_tetr = 0;
	min = 0;
	map = ft_read_map(argc[1]);
	number_tetr = ft_number_tetrimino(map);
	val_tetr = ft_card_split(map, number_tetr);
    if (argv < 2)
        ft_putendl("usage: fillit source_file");
	if (ft_chek(val_tetr, map, number_tetr) < 0)
		write(1, "error\n", 6);
	//ft_free_field(val_tetr);
	tetriminos = ft_tetrimino(map, number_tetr);
	//free(map);
	min = ft_sqrt(number_tetr * 4);
	ft_clean_row_point(tetriminos);
	ft_clean_column_point(tetriminos);
	ft_to_alphabet(tetriminos);
	ft_solving(tetriminos, number_tetr);
}
