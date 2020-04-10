/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:47:16 by whumfrey          #+#    #+#             */
/*   Updated: 2019/02/26 15:01:40 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_chek_map(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '.' && map[i] != '#' && map[i] != '\n')
			return (-1);
		if (map[i] == '\n' && map[i + 1] == '\n' && map[i + 2] == '\n')
			return (-1);
		i++;
	}
	if (map[i - 1] == '\n' && map[i - 2] == '\n')
		return (-1);
	return (1);
}

int	ft_chek_tetriminos(char **tetriminos, int number_tetrimino)
{
	int		x;
	int		y;
	int		touch;

	x = 0;
	while (x < number_tetrimino)
	{
		y = 0;
		touch = 0;
		while (tetriminos[x][y])
		{
			if (tetriminos[x][y] == '#')
				touch += ft_count_touch(tetriminos[x], y);
			y++;
		}
		x++;
		if (touch != 6 && touch != 8)
			return (-1);
	}
	return (1);
}

int	ft_chek_point(char **tetriminos, int number_tetrimino)
{
	int	x;
	int	y;
	int	point;

	x = 0;
	while (x < number_tetrimino)
	{
		y = 0;
		point = 0;
		while (tetriminos[x][y])
		{
			if (tetriminos[x][y] == '.')
				point++;
			y++;
		}
		x++;
		if (point != 12)
			return (-1);
	}
	return (1);
}

int	ft_chek(char **tetriminos, char *map, int number_tetrimino)
{
	if (ft_chek_tetriminos(tetriminos, number_tetrimino) < 0)
		return (-1);
	if (ft_chek_point(tetriminos, number_tetrimino) < 0)
		return (-1);
	if (ft_chek_map(map) < 0)
		return (-1);
	return (1);
}
