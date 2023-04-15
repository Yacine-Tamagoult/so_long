/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:30:45 by soleil            #+#    #+#             */
/*   Updated: 2023/04/15 22:42:00 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf ("%c\n", keycode);
	if (keycode == 'a')
		vars->next = vars->map[(vars->Perso_Y / 50)][(vars->Perso_X / 50) - 1];
	else if (keycode == 's')
		vars->next = vars->map[(vars->Perso_Y / 50) + 1][(vars->Perso_X / 50)];
	else if (keycode == 'w')
		vars->next = vars->map[(vars->Perso_Y / 50) - 1][(vars->Perso_X / 50)];
	else if (keycode == 'd')
		vars->next = vars->map[(vars->Perso_Y / 50)][(vars->Perso_X / 50) + 1];
	else if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	if (vars->next != '1' && (vars->Count_Collect == 0 || vars->next != 'E'))
	{
		if (keycode == 'a')
			move_up(vars);
		if (keycode == 's')
			move_down(vars);
		if (keycode == 'w')
			move_left(vars);
		if (keycode == 'd')
			move_right(vars);
	}
	return (0);
}

int	move_up(t_vars *vars)
{
	mlx_put_image_to_window (vars->mlx, vars->win, vars->flor,
		vars->Perso_X, vars->Perso_Y);
	mlx_destroy_image (vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image (vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->perso,
		vars->Perso_X - 50, vars->Perso_Y);
	vars->Perso_X = vars->Perso_X - 50;
	if (vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] == 'C')
	{	
		vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] = '0';
		vars->Count_Collect--;
	}
	if (vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y
		&& vars->Count_Collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}

int	move_down(t_vars *vars)
{
	mlx_put_image_to_window (vars->mlx, vars->win, vars->flor,
		vars->Perso_X, vars->Perso_Y);
	mlx_destroy_image (vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image (vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->perso,
		vars->Perso_X, vars->Perso_Y + 50);
	vars->Perso_Y = vars->Perso_Y + 50;
	if (vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] == 'C')
	{
		vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] = '0';
		vars->Count_Collect--;
	}
	if (vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y
		&& vars->Count_Collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}

int	move_right(t_vars *vars)
{
	mlx_put_image_to_window (vars->mlx, vars->win, vars->flor,
		vars->Perso_X, vars->Perso_Y);
	mlx_destroy_image (vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image(vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso,
		vars->Perso_X + 50, vars->Perso_Y);
	vars->Perso_X = vars->Perso_X + 50;
	if (vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] == 'C')
	{
		vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] = '0';
		vars->Count_Collect--;
	}
	if (vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y
		&& vars->Count_Collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}

int	move_left(t_vars *vars)
{
	mlx_put_image_to_window (vars->mlx, vars->win, vars->flor,
		vars->Perso_X, vars->Perso_Y);
	mlx_destroy_image (vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image (vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->perso,
		vars->Perso_X, vars->Perso_Y - 50);
	vars->Perso_Y = vars->Perso_Y - 50;
	if (vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] == 'C')
	{
		vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] = '0';
		vars->Count_Collect--;
	}
	if (vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y
		&& vars->Count_Collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}
