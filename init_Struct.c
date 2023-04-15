/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_Struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:55:53 by soleil            #+#    #+#             */
/*   Updated: 2023/04/15 21:55:55 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_vars *vars)
{
	vars->img_width = 5;
	vars ->img_height = 5;
	vars->perso = mlx_xpm_file_to_image (vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	vars->wall = mlx_xpm_file_to_image (vars->mlx, "image/mur.xpm",
			&vars->img_width, &vars->img_height);
	vars->flor = mlx_xpm_file_to_image (vars->mlx, "image/sol.xpm",
			&vars->img_width, &vars->img_height);
	vars->door = mlx_xpm_file_to_image (vars->mlx, "image/Porte.xpm",
			&vars->img_width, &vars->img_height);
	vars->collect = mlx_xpm_file_to_image(vars->mlx, "image/collect.xpm",
			&vars->img_width, &vars->img_height);
}

int	ft_count(char **tab, t_vars *vars)
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
	vars->col = j;
	vars->row = i;
}

void	print_image(t_vars *vars, char c, int x, int y)
{	
	if (c == '1')
		mlx_put_image_to_window (vars->mlx, vars->win, vars->wall, x, y);
	else if (c == 'P')
		mlx_put_image_to_window (vars->mlx, vars->win, vars->perso, x, y);
	else if (c == '0')
		mlx_put_image_to_window (vars->mlx, vars->win, vars->flor, x, y);
	else if (c == 'E')
		mlx_put_image_to_window (vars->mlx, vars->win, vars->door, x, y);
	else if (c == 'C')
		mlx_put_image_to_window (vars->mlx, vars->win, vars->collect, x, y);
}

void	zgag(t_vars *vars)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = 0;
	j = 0;
	x = 0;
	i = 0;
	while (i < vars->row)
	{
		print_image(vars, vars->map[i][j], x, y);
		j++;
		x += 50;
		if (j == vars->col)
		{
			y += 50;
			x = 0;
			i++;
			j = 0;
		}
	}
}
