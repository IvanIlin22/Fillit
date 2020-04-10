/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:10:12 by whumfrey          #+#    #+#             */
/*   Updated: 2019/02/26 17:16:49 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_substitution_tetra(char **field, char **tetriminos, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] != '.')
				field[x + i][y + j] = tetriminos[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_chek_substitution(char **field, char **tetriminos, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (tetriminos[i])
	{
		if (field[x + i] == 0)
			return (0);
		j = 0;
		while (tetriminos[i][j])
		{
			if (field[x + i][y + j] == 0)
				return (0);
			if (tetriminos[i][j] != '.' && field[x + i][y + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_clean_field(char **field, char **tetriminos, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] != '.')
				field[x + i][y + j] = '.';
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_solver(char **field, char ***tetriminos, int b)
{
	int		i;
	int		j;

	i = 0;
	if (tetriminos[b] == 0)
		return (0);
	while (field[i])
	{
		j = 0;
		while (field[i][j])
		{
			if (ft_chek_substitution(field, tetriminos[b], i, j))
			{
				ft_substitution_tetra(field, tetriminos[b], i, j);
				if (!ft_solver(field, tetriminos, b + 1))
					return (0);
				ft_clean_field(field, tetriminos[b], i, j);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_solving(char ***tetriminos, int number_tetr)
{
	char	**field;
	int		min;
    
	min = ft_sqrt(number_tetr * 4);
	field = ft_creature_field(min, min);
	while (ft_solver(field, tetriminos, 0))
	{
		min++;
		ft_free_field(field);
		field = ft_creature_field(min, min);
	}
	ft_print_field(field);
	return (0);
}
