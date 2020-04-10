/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrumetns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:08:28 by whumfrey          #+#    #+#             */
/*   Updated: 2019/02/26 17:37:56 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_creature_field(int m, int n)
{
	int		i;
	int		j;
	char	**field;

	i = 0;
	field = (char**)malloc(sizeof(char*) * (n + 1));
	while (i < n)
	{
		field[i] = (char*)malloc(sizeof(char) * (m + 1));
		j = 0;
		while (j < m)
		{
			field[i][j] = '.';
			j++;
		}
		field[i][j] = 0;
		i++;
	}
	field[i] = NULL;
	return (field);
}

int	ft_clean_row_point(char ***matrix)
{
	int		k;
	int		i;
	int		j;

	k = 0;
	while (matrix[k])
	{
		i = 0;
		while (matrix[k][i])
		{
			if (!ft_strcmp(matrix[k][i], "...."))
			{
				j = i--;
				while (matrix[k][j])
				{
					matrix[k][j] = matrix[k][j + 1];
					j++;
				}
			}
			i++;
		}
		k++;
	}
	return (0);
}

int	ft_clean_column(char ***tetriminos, int k, int i, int j)
{
	int		j2;

	j2 = 0;
	while (tetriminos[k][i])
	{
		if (tetriminos[k][i][j] == '.')
			j2++;
		i++;
	}
	if (i == j2)
	{
		i = 0;
		while (tetriminos[k][i])
		{
			j2 = j;
			while (tetriminos[k][i][j2])
			{
				tetriminos[k][i][j2] = tetriminos[k][i][j2 + 1];
				j2++;
			}
			i++;
		}
		j--;
	}
	return (j);
}

int	ft_clean_column_point(char ***tetriminos)
{
	int		k;
	int		i;
	int		j;

	k = 0;
	while (tetriminos[k])
	{
		i = 0;
		j = 0;
		while (tetriminos[k][i][j])
		{
			j = ft_clean_column(tetriminos, k, i, j);
			j++;
		}
		k++;
	}
	return (0);
}

void	ft_to_alphabet(char ***tetriminos)
{
	int		k;
	int		i;
	int		j;
	char	c;

	k = 0;
	c = 'A';
	while (tetriminos[k])
	{
		i = 0;
		while (tetriminos[k][i])
		{
			j = 0;
			while (tetriminos[k][i][j])
			{
				if (tetriminos[k][i][j] == '#')
					tetriminos[k][i][j] = c;
				j++;
			}
			i++;
		}
		k++;
		c++;
	}
}
