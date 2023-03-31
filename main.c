#include "so_long.h"



int ftstrlen(char *str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}




char **ft_maps(char *str, char **tab)
{
	static int i = 0;
	char **map;
	int j = i - 1;
	int k = 0; 

	map = malloc(sizeof(char*) * i + 2);
	map[i] = malloc(sizeof(char) * ftstrlen(str) + 1);
	while(j >= 0)
	{
		k = 0;
		map[j] = malloc(sizeof(char) * ftstrlen(tab[j]) + 1);
		while(tab[j][k])
		{
			map[j][k] = tab[j][k];
			k++;
		}
		map[j][k] = 0;
		j--;
	}
	k = 0;
	while(str[k])
	{
		map[i][k] = str[k];
		k++;
	}
	map[i][k] = 0;
	map[i + 1] = NULL;
	i++;
	// ft_check_master(map);
	return(map);
}

int main(int ac, char **av)
{	
	t_vars	vars;
	
	char	*str;
	int fd = open(av[1], O_RDONLY);
	int i = 0;
	char **tab;
	int j = 0;
	int k = 0;

	if (fd >= 0)
	{
		str = get_next_line(fd);
		while (str)
		{
			tab = ft_maps(str, tab);
			i++;
			free(str);
			str = get_next_line(fd);
		}
	}
	i = 0;
	// if(ft_check_master(tab))
	// 	return (1);
	
	
		ft_count(tab,&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.col * 50, vars.row * 50, "Many Corp");
		init_image(&vars);
		zgag(&vars,tab);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop(vars.mlx); 

	return (0);
}























// -- PERMET DE FERMER LA FENETRE SUR UNE TOUCHE -- \\


/*
 int	close(int keycode, t_vars *vars)
 {
 	mlx_destroy_window(vars->mlx, vars->win);
 	return (0);
 }

 int	main(void)
 {
 	t_vars	vars;

 	vars.mlx = mlx_init();
 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
 	mlx_hook(vars.win, 2, 1L<<2, close, &vars);
 	mlx_loop(vars.mlx);
 }

*/








// -- PERMET DE COMPTER LE NBR DE MOUVEMENT -- \\


// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;	
// }				t_vars;





// int	key_hook(int keycode, t_vars *vars)
// {
// 	static int i = 0;

// 	printf("Move :%d\n",i);
// 	i++;

// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }








































// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void 	*vars.win;
// 	int i;
// 	int x;
// 	int y;

// 	t_data img;
// 	x = 450;
// 	y = 100;
// 	i = 8;
// 	mlx = mlx_init();
// 	vars.win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	vars.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(vars.img, &img.bits_per_pixel, &img.line_length,&img.endian);

// 	my_mlx_pixel_put(&img, 5, 5, 0xFF0000);
	
// 	while(i >= 0)
// 	{
// 		mlx_put_image_to_window(mlx, vars.win, vars.img, x, y);
// 		x += 10;
// 		i--;
// 	}
// 	i = 7;
// 	x = 450;
// 	y = 110;
// 	while(i >= 0)
// 	{
// 		mlx_put_image_to_window(mlx, vars.win, vars.img, x, y);
// 		y += 10;
// 		i--;
// 	}
// 	i = 7;
// 	x = 460;
// 	y = 180;
// 	while(i >= 0)
// 	{
// 		mlx_put_image_to_window(mlx, vars.win, vars.img, x, y);
// 		x += 10;
// 		i--;
// 	}
	
	
// 	mlx_loop(mlx);
// }














// int	main(void)
// {
// 	void	*mlx;
// 	void	*vars.win;
// 	void 	*img;
// 	char 	*relative_path = "/mnt/nfs/homes/yatamago/Desktop/so_long/img/549ehr6p2uq21.xpm";
// 	int 	img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	vars.win = mlx_new_window(mlx, 1020, 900, "Hello world!");

// 	mlx_put_image_to_window(mlx, vars.win, img, 5,5);
// 	mlx_loop(mlx);
// }
