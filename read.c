/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:58:05 by whumfrey          #+#    #+#             */
/*   Updated: 2019/02/26 20:12:25 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_read_map(char *argv)
{
	int			nb;
    int			fd;
	char		buf[BUFF_SIZE + 1];
	static char	*map;

	fd = 0;
	if (BUFF_SIZE < 0 || !(map = ft_strnew(1)))
		return (NULL);
	fd = open(argv, O_RDONLY);
	while ((nb = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nb] = '\0';
		map = ft_strjoin(map, buf);
	}
	return (map);
}

int		ft_number_tetrimino(char *map)
{
	int			space;
	int			i;
	int			number_tetrimino;

	i = 0;
	space = 0;
	number_tetrimino = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			space++;
		i++;
	}
	number_tetrimino = (space + 1) / 5;
	return (number_tetrimino);
}

char		**ft_card_split(char *map, int number_tetrimino)
{
	int			x;
	int			y;
	int			i;
	char		**tetriminos;

	i = 0;
	x = 0;
	if (!(tetriminos = (char**)malloc(sizeof(char*) * (number_tetrimino + 1))))
		return (NULL);
	while (x < number_tetrimino)
	{
		if (!(tetriminos[x] = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		y = 0;
		while (y < 20)
		{
			tetriminos[x][y] = map[i];
			y++;
			i++;
		}
		tetriminos[x][y] = '\0';
		i++;
		x++;
	}
	return (tetriminos);
}

char		***ft_tetrimino(char *map, int number_tetrimino)
{
	int			x;
	int			y;
	int			z;
	int			i;
	char		***tetriminos;

	i = 0;
	x = -1;
	if (!(tetriminos = (char***)malloc(sizeof(char**) * (number_tetrimino + 1))))
		return (NULL);
	while (++x < number_tetrimino)
	{
		if (!(tetriminos[x] = (char**)malloc(sizeof(char*) * 5)))
			return (NULL);
		y = 0;
		while (y < 4)
		{
			if (!(tetriminos[x][y] = (char*)malloc(sizeof(char) * 5)))
				return (NULL);
			z = 0;
			while (z < 4)
			{
				tetriminos[x][y][z] = map[i];
				z++;
				i++;
			}
			tetriminos[x][y][z] = '\0';
			i++;
			y++;
		}
		i++;
	}
	return (tetriminos);
}

int		ft_count_touch(char *map, int i)
{
	int			n;

	n = 0;
	if (map[i - 1] == '#')
		n++;
	if (map[i - 5] == '#')
		n++;
	if (map[i + 1] == '#')
		n++;
	if (map[i + 5] == '#')
		n++;
	return (n);
}
