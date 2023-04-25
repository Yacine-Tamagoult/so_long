/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:10:40 by soleil            #+#    #+#             */
/*   Updated: 2023/04/25 16:23:10 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif_c_et_e(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == 'C' || tab[j][i] == 'E')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_nombre_de_e_c(char **map, char c)
{
	int	j;
	int	i;
	int	compte;

	j = 0;
	compte = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				compte++;
			i++;
		}
		j++;
	}
	return (compte);
}

int	is_valid_position(char **map, int i, int j)
{
	if (j >= 0 && map[j] && i >= 0 && map[j][i])
		return (1);
	return (0);
}

int	verif_emplacement(char **fmap, char *map, int *e, char *pos)
{
	t_vars	vars;

	vars.i = pos[0];
	vars.j = pos[1];
	if (!is_valid_position(fmap, vars.i, vars.j))
		return (1);
	if (*map == '0' || *map == 'C' || *map == 'E')
	{
		if (*map == 'E' && ft_nombre_de_e_c(fmap, 'C') != 0)
		{
			*e = *e + 1;
			return (1);
		}
		if (*map == 'E')
		{
			*e = *e + 1;
			*map = 'e';
		}
		if (*map == 'C')
			*map = 'c';
		if (*map == '0')
			*map = '2';
		return (0);
	}
	return (1);
}

int	ft_valid_path(char **map, int i, int j, t_vars *vars)
{
	static int	dr[8] = {0, 0, -1, 1, 1, -1, 0, 0};
	int			i2;
	int			j2;
	static int	e = 0;
	int			o;

	o = 0;
	if (ft_nombre_de_e_c(map, 'E') != 0 || ft_nombre_de_e_c(map, 'C') != 0)
	{
		while (o < 4)
		{
			j2 = j + dr[o];
			i2 = i + dr[o + 4];
			vars->pos[0] = i2;
			vars->pos[1] = j2;
			if (is_valid_position(map, i2, j2)
				&& verif_emplacement(map, &map[j2][i2], &e, vars->pos) == 0)
				ft_valid_path(map, i2, j2, vars);
			o++;
		}
	}
	if (e == 0 || ft_nombre_de_e_c(map, 'C') > 0)
		return (0);
	return (1);
}
