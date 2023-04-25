/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:06:21 by soleil            #+#    #+#             */
/*   Updated: 2023/04/25 16:55:33 by soleil           ###   ########.fr       */
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

	topnbot = 0;
	while (topnbot < k)
	{
		if (tab[i][topnbot] != '1')
			return (1);
		topnbot++;
	}
	return (0);
}

void	count_characters(char **tab, t_vars *vars, int counts[3])
{
	while (tab[vars->counti])
	{
		vars->countj = 0;
		while (tab[vars->counti][vars->countj])
		{
			if (tab[vars->counti][vars->countj] == 'C')
				counts[0]++;
			if (tab[vars->counti][vars->countj] == 'P')
			{
				counts[1]++;
				vars->x = vars->countj;
				vars->y = vars->counti;
				vars->perso_x = vars->countj * 50;
				vars->perso_y = vars->counti * 50;
			}
			if (tab[vars->counti][vars->countj] == 'E')
			{
					vars->porte_x = vars->countj * 50;
					vars->porte_y = vars->counti * 50;
					counts[2]++;
			}
			vars->countj++;
		}
		vars->counti++;
	}
}

int	ft_check_cpe(char **tab, t_vars *vars)
{
	static int	counts[3] = {0, 0, 0};

	count_characters(tab, vars, counts);
	vars->count_collect = counts[0];
	if (counts[1] != 1 || counts[2] != 1 || counts[0] < 1)
		return (1);
	else if (ft_valid_path(tab, vars->y, vars->x, vars) == 0)
		return (1);
	return (0);
}

int	escape(int key, t_vars *vars)
{
	freetoutmescopains(vars);
	exit (0);
}
