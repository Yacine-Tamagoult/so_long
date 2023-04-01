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
char **ft_copy_map(char **tab)
{
    int i = 0;
    int j;

    while (tab[i])
        i++;
    char **copy = (char **)malloc((i + 1) * sizeof(char *));
    if (!copy)
        return (NULL);
    copy[i] = NULL;
    j = 0;
    while (j < i)
    {
        copy[j] = strdup(tab[j]);
        if (!copy[j])
        {
            while (j > 0)
            {
                j--;
                free(copy[j]);
            }
            free(copy);
            return (NULL);
        }
        j++;
    }
    return (copy);
}

char **ft_maps(char *str, char **tab)
{
	static int i = 0;
	char **map;
	int j = i - 1;
	int k = 0; 

	map = malloc(sizeof(char*) * (i + 2));
	map[i] = malloc(sizeof(char) * (ftstrlen(str) + 1));
	while(j >= 0)
	{
		k = 0;
		map[j] = malloc(sizeof(char) * (ftstrlen(tab[j]) + 1));
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

char **ft_Fd_init(char *file)
{	
	int i = 0;
	char	*str;
	char 	**tab;
	int fd = open(file, O_RDONLY);
	
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
	return(tab);
}

int main(int ac, char **av)
{	
	t_vars	vars;

	int j = 0;
	int k = 0;
	vars.map = ft_copy_map(ft_Fd_init(av[1]));
	vars.Check_map = ft_copy_map(vars.map);
	if(ft_check_master(vars.Check_map, &vars))
		return (1);
	ft_count(vars.Check_map,&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.col * 50, vars.row * 50, "Many Corp");
	init_image(&vars);
	zgag(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx); 
	return (0);
}
