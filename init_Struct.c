#include "so_long.h"

void init_image(t_vars *vars)
{
    int img_width;
    int img_height;

    img_width = 5;
    img_height = 5;
    vars->perso = mlx_xpm_file_to_image(vars->mlx,"/home/soleil/Desktop/so_long/image/Faceset.xpm", &img_width, &img_height);
    vars->wall = mlx_xpm_file_to_image(vars->mlx,"/home/soleil/Desktop/so_long/image/rock_in_water_06.xpm",&img_width, &img_height);
    
}


int ft_count(char **tab, t_vars *vars)
{
	int i = 0;
	int j;

	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			j++;
		}
		
		i++;
	}
	vars->col = j;
	vars->row = i; 
}

void	Print_image(char **tab)
{	

	t_vars vars;
	int i = 0;
	int j;
	int x;
	int y = 0;

	while(tab[i])
	{	
		x = 0;
		j = 0;
		while(tab[i][j])
		{
			if(j == '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, vars.wall, x, y);
				x = x + 50;
			}
	
			else if(j == 'P')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, vars.perso, x, y);
				x = x + 50;
			}
			
			j++;
		}
		y = y + 50;
		
		i++;
	}

		
	
}

