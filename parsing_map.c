/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:09:17 by soleil            #+#    #+#             */
/*   Updated: 2023/04/15 23:28:38 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_line(char **tab)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = ftstrlen(tab[0]);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (temp != j)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_wall(char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = ftstrlen(tab[0]);
	if (ft_check_horizontal(tab, i, k))
		return (1);
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] != '1')
			return (1);
		while (tab[i][j])
			j++;
		if (tab[i][j - 1] != '1')
			return (1);
		i++;
	}
	if (ft_check_horizontal(tab, i - 1, k))
		return (1);
	return (0);
}

int	ft_check_parasit(char **tab)
{
	int	i;
	int	j;
	int	searchpara;

	i = 0;
	searchpara = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != 'C' && tab[i][j] != 'E' && tab[i][j] != 'P'
					&& tab[i][j] != '1' && tab[i][j] != '0')
				searchpara++;
			j++;
		}
		i++;
	}
	if (searchpara != 0)
		return (1);
	return (0);
}

int	ft_check_square(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		i++;
	}
	if (i == j)
		return (1);
	return (0);
}

int	ft_check_master(char **map, t_vars *vars)
{
	if (ft_check_line(map))
		return (printf ("2\n"), 1);
	else if (ft_check_wall(map))
		return (printf ("3\n"), 1);
	else if (ft_check_parasit(map))
		return (printf ("4\n"), 1);
	else if (ft_check_square(map))
		return (printf ("5\n"), 1);
	else if (ft_check_cpe(map, vars))
		return (printf ("6\n"), 1);
	return (0);
}
