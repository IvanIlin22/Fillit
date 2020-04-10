/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrumetns2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:40:14 by whumfrey          #+#    #+#             */
/*   Updated: 2019/02/26 19:40:25 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_sqrt(int number_tetrimino)
{
	int		i;

	i = 2;
	while (i * i < number_tetrimino)
		i++;
	return (i);
}

int	ft_free_field(char **field)
{
	int		i;

	i = 0;
	while (field[i])
	{
		free(field[i]);
		i++;
	}
	free(field);
	field = NULL;
	return (0);
}

int	ft_print_field(char **field)
{
	int i;

	i = 0;
	while (field[i] != 0)
	{
		ft_putendl(field[i]);
		i++;
	}
	return (0);
}
