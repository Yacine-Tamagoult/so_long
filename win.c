#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
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
			Move_Up(vars);
		if (keycode == 's')
			Move_Down(vars);
		if (keycode == 'w')
			Move_Left(vars);
		if (keycode == 'd')
			Move_Right(vars);
	}
	return (0);
}

int	Move_Up(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, vars->Perso_X,vars->Perso_Y);
	mlx_destroy_image(vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image(vars->mlx,"image/moi.xpm", &vars->img_width,&vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->Perso_X - 50, vars->Perso_Y);
	vars->Perso_X = vars->Perso_X - 50;
	if(vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] == 'C')
	{	
		vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] = '0';
		vars->Count_Collect--;
	}
	if(vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y && vars->Count_Collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}

int Move_Down(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, vars->Perso_X, vars->Perso_Y);
	mlx_destroy_image(vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image(vars->mlx,"image/moi.xpm", &vars->img_width,&vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->Perso_X, vars->Perso_Y + 50);
	vars->Perso_Y = vars->Perso_Y  + 50;
	if(vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] == 'C')
	{
		vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] = '0';
		vars->Count_Collect--;
	}
	if(vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y && vars->Count_Collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}

int Move_Right(t_vars *vars)
{
	
	mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, vars->Perso_X, vars->Perso_Y);
	mlx_destroy_image(vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image(vars->mlx,"image/moi.xpm", &vars->img_width,&vars->img_height);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->Perso_X + 50, vars->Perso_Y);
	vars->Perso_X = vars->Perso_X + 50;
	if(vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] == 'C')
	{
		vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] = '0';
		vars->Count_Collect--;
	}
	if(vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y && vars->Count_Collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}

int Move_Left(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, vars->Perso_X, vars->Perso_Y);
	mlx_destroy_image(vars->mlx, vars->perso);
	vars->perso = mlx_xpm_file_to_image(vars->mlx,"image/moi.xpm", &vars->img_width,&vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->Perso_X , vars->Perso_Y - 50);
	vars->Perso_Y = vars->Perso_Y  - 50;
	
	if(vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] == 'C')
	{
		vars->map[vars->Perso_Y / 50][vars->Perso_X / 50] = '0';
		vars->Count_Collect--;
	}
	if(vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y && vars->Count_Collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}
