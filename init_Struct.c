#include "so_long.h"

void init_image(t_vars *vars)
{
    int img_width;
    int img_height;

    img_width = 5;
    img_height = 5;
    vars->perso = mlx_xpm_file_to_image(vars->mlx,"/home/soleil/Desktop/so_long/image/moi.xpm", &img_width, &img_height);
    vars->wall = mlx_xpm_file_to_image(vars->mlx,"/home/soleil/Desktop/so_long/image/mur.xpm",&img_width, &img_height);
    //vars->flor = mlx_xpm_file_to_image(vars->mlx,"/home/soleil/Desktop/so_long/image/wooden.xpm",&img_width, &img_height);
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

void	Print_image(t_vars *vars, char c, int x, int y)
{	
	if(c == '1')
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x, y) ;
	else if(c == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, x, y);
	}
	
	// else if(c == '0')
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->flor, x, y);
}

void	zgag(t_vars *vars, char **tab)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = 0;
	j = 0;
	x = 0;
	i = 0;
	while (i < vars->row )
	{
		Print_image(vars, tab[i][j], x, y);
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


