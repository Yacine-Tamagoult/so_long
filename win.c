/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:30:45 by soleil            #+#    #+#             */
/*   Updated: 2023/04/25 16:16:02 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




void freetoutmescopains(t_vars *vars)
{
	
	mlx_destroy_image(vars->mlx, vars->door);
	mlx_destroy_image(vars->mlx, vars->flor);
	mlx_destroy_image(vars->mlx, vars->perso);
	mlx_destroy_image(vars->mlx, vars->collect);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_map(vars->map);
	free_map(vars->check_map);
	free(vars->mlx);
}
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		printf ("Moves: %d\n", vars->movecount++);
	if (keycode == 'a')
		vars->next = vars->map[(vars->perso_y / 50)][(vars->perso_x / 50) - 1];
	else if (keycode == 's')
		vars->next = vars->map[(vars->perso_y / 50) + 1][(vars->perso_x / 50)];
	else if (keycode == 'w')
		vars->next = vars->map[(vars->perso_y / 50) - 1][(vars->perso_x / 50)];
	else if (keycode == 'd')
		vars->next = vars->map[(vars->perso_y / 50)][(vars->perso_x / 50) + 1];
	else if (keycode == 65307)
		escape(keycode, vars);
	if (vars->next != '1' && (vars->count_collect == 0 || vars->next != 'E'))
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
		vars->perso_x, vars->perso_y);
	mlx_destroy_image (vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image (vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->perso,
		vars->perso_x - 50, vars->perso_y);
	vars->perso_x = vars->perso_x - 50;
	if (vars->map[vars->perso_y / 50][vars->perso_x / 50] == 'C')
	{	
		vars->map[vars->perso_y / 50][vars->perso_x / 50] = '0';
		vars->count_collect--;
	}
	if (vars->perso_x == vars->porte_x && vars->perso_y == vars->porte_y
		&& vars->count_collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		freetoutmescopains(vars);
		exit(EXIT_SUCCESS);
	}
}

int	move_down(t_vars *vars)
{
	mlx_put_image_to_window (vars->mlx, vars->win, vars->flor,
		vars->perso_x, vars->perso_y);
	mlx_destroy_image (vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image (vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->perso,
		vars->perso_x, vars->perso_y + 50);
	vars->perso_y = vars->perso_y + 50;
	if (vars->map[vars->perso_y / 50][vars->perso_x / 50] == 'C')
	{
		vars->map[vars->perso_y / 50][vars->perso_x / 50] = '0';
		vars->count_collect--;
	}
	if (vars->perso_x == vars->porte_x && vars->perso_y == vars->porte_y
		&& vars->count_collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		freetoutmescopains(vars);
		exit(EXIT_SUCCESS);
	}
}

int	move_right(t_vars *vars)
{
	mlx_put_image_to_window (vars->mlx, vars->win, vars->flor,
		vars->perso_x, vars->perso_y);
	mlx_destroy_image (vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image(vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso,
		vars->perso_x + 50, vars->perso_y);
	vars->perso_x = vars->perso_x + 50;
	if (vars->map[vars->perso_y / 50][vars->perso_x / 50] == 'C')
	{
		vars->map[vars->perso_y / 50][vars->perso_x / 50] = '0';
		vars->count_collect--;
	}
	if (vars->perso_x == vars->porte_x && vars->perso_y == vars->porte_y
		&& vars->count_collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		freetoutmescopains(vars);
		exit(EXIT_SUCCESS);
	}
}

int	move_left(t_vars *vars)
{
	mlx_put_image_to_window (vars->mlx, vars->win, vars->flor,
		vars->perso_x, vars->perso_y);
	mlx_destroy_image (vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image (vars->mlx, "image/moi.xpm",
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->perso,
		vars->perso_x, vars->perso_y - 50);
	vars->perso_y = vars->perso_y - 50;
	if (vars->map[vars->perso_y / 50][vars->perso_x / 50] == 'C')
	{
		vars->map[vars->perso_y / 50][vars->perso_x / 50] = '0';
		vars->count_collect--;
	}
	if (vars->perso_x == vars->porte_x && vars->perso_y == vars->porte_y
		&& vars->count_collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		freetoutmescopains(vars);
		exit(EXIT_SUCCESS);
	}
}
