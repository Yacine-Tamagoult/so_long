/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:06:21 by soleil            #+#    #+#             */
/*   Updated: 2023/04/15 23:37:24 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		free (map[j]);
		j++;
	}
	free (map);
	return (1);
}

int	ft_check_horizontal(char **tab, int i, int k)
{
	int	topnbot;

	topnbot = 1;
	while (topnbot < k)
	{
		if (tab[i][topnbot] != '1')
			return (1);
		topnbot++;
	}
	return (0);
}

int	ft_check_cpe(char **tab, t_vars *vars)
{
	int	i;
	int	j;
	int	c;
	int	p;
	int	e;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				c++;
			if (tab[i][j] == 'P')
			{
				p++;
				vars->x = j;
				vars->y = i;
				vars->Perso_X = j * 50;
				vars->Perso_Y = i * 50;
			}
			if (tab[i][j] == 'E')
			{	
				vars->Porte_X = j * 50;
				vars->Porte_Y = i * 50;
				e++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	vars->Count_Collect = c;
	if (p != 1 || e != 1 || c != 1)
		return (1);
	else if (ft_valid_path(tab, vars->y, vars->x, vars) == 0)
		return (1);
	return (0);
}
