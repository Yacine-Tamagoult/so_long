#include "so_long.h"



int	key_hook(int keycode, t_vars *vars)
{
	static int i = 0;
	if (keycode == 119 || keycode == 115 |keycode == 97 |keycode == 114)
	{
		printf("Move :%d\n",i);
		i++;
	}
	if(keycode == 114)
	{	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, vars->Perso_X, vars->Perso_Y);
		mlx_destroy_image(vars->mlx, vars->perso);
		vars->perso = mlx_xpm_file_to_image(vars->mlx,"image/moi.xpm", &vars->img_width,&vars->img_height);
		if(vars->collect)
		{
			vars->Count_Collect--;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->Perso_X, vars->Perso_Y + 50);
		vars->Perso_Y = vars->Perso_Y  + 50;
		if(vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y && vars->Count_Collect == 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
		}
	}
	else if(keycode == 97)
	{	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, vars->Perso_X, vars->Perso_Y);
		mlx_destroy_image(vars->mlx, vars->perso);
		vars->perso = mlx_xpm_file_to_image(vars->mlx,"image/moi.xpm", &vars->img_width,&vars->img_height);
		if(vars->collect)
		{
			vars->Count_Collect--;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->Perso_X - 50, vars->Perso_Y);
		vars->Perso_X = vars->Perso_X - 50;
		if(vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y && vars->Count_Collect == 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
		}
	}
	else if(keycode == 119)
	{	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, vars->Perso_X, vars->Perso_Y);
		mlx_destroy_image(vars->mlx, vars->perso);
		vars->perso = mlx_xpm_file_to_image(vars->mlx,"image/moi.xpm", &vars->img_width,&vars->img_height);
		if(vars->collect)
		{
			vars->Count_Collect--;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->Perso_X , vars->Perso_Y - 50);
		vars->Perso_Y = vars->Perso_Y  - 50;
		if(vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y && vars->Count_Collect == 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
		}
	}
	else if(keycode == 115)
	{	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, vars->Perso_X, vars->Perso_Y);
		mlx_destroy_image(vars->mlx, vars->perso);
		vars->perso = mlx_xpm_file_to_image(vars->mlx,"image/moi.xpm", &vars->img_width,&vars->img_height);
		if(vars->collect)
		{
			vars->Count_Collect--;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->Perso_X + 50, vars->Perso_Y);
		vars->Perso_X = vars->Perso_X + 50;
		if(vars->Perso_X == vars->Porte_X && vars->Perso_Y == vars->Porte_Y && vars->Count_Collect == 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
		}
	}
	else if(keycode == 65307)
	{
		mlx_destroy_window(vars->mlx,vars->win);
		exit;
	}
}


