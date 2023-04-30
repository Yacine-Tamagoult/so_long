/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusdeplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:07:33 by soleil            #+#    #+#             */
/*   Updated: 2023/04/30 23:11:02 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->col * 50,
			vars->row * 50, "Many Corp");
	init_image(vars);
	zgag(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}

void	freetoutmescopains(t_vars *vars)
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
