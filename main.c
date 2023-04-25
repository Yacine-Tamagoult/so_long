/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:56:35 by soleil            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/25 20:03:06 by soleil           ###   ########.fr       */
=======
/*   Updated: 2023/04/25 19:47:17 by ilselbon         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(char **tab)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	if(!tab)
		return (NULL);
	while (tab[i])
		i++;
`
	if (!copy)
		return (NULL);
	copy[i] = NULL;
	j = 0;
	while (j < i)
	{
		copy[j] = strdup(tab[j]);
		if (!copy[j])
		{
			while (j-- > 0)
				free(copy[j]);
			return (free(copy), NULL);
		}
		j++;
	}
	int o = 0;
	while(tab[o])
	{
		free(tab[o]);
		o++;
	}
	free(tab);
	return (copy);
}

char	**ft_maps(char *str, char **tab)
{
	static int	i = 0;
	char		**map;
	int			j;
	int			k;

	j = i - 1;
	k = 0;
	map = malloc(sizeof(char *) * (i + 2));
	map[i] = malloc(sizeof(char) * (ftstrlen(str) + 1));
	while (j >= 0)
	{
		k = 0;
		map[j] = strdup(tab[j]);
		j--;
	}
	k = 0;
	while (str[k])
		map[i][k++] = str[k];
	map[i][k] = 0;
	map[i + 1] = NULL;
	i++;
	return (map);
}

int	ft_check_ber(char *file)
{
	char	*ber;
	int		i;
	int		j;

	ber = ".ber";
	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i] == ber[j])
			j++;
		i++;
	}
	if (!ber[j])
	{
		return (0);
	}
	return (1);
}

char	**ft_fd_init(char *file)
{	
	int		i;
	char	*str;
	char	**tab;
	char	**tmp;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if(!str)
		return (NULL);
	while (str)
	{
		tab = ft_maps(str, tab);
		i++;
		free(str);
		str = get_next_line(fd);
	}
	return (tab);	
}

int main(int ac, char **av)
{
    t_vars vars;
	char **tab;
    int j;
    int k;

    k = 0;
    j = 0;
    if (ac != 2)
        return (1);
    if (ft_check_ber(av[1]))
        return (printf("Error\n"), 1);
    memset(&vars, 0, sizeof(vars));
	tab = ft_fd_init(av[1]);
    vars.map = ft_copy_map(tab);
    if (!vars.map)
        return (printf("error"), 1);
    vars.check_map = ft_copy_map(vars.map);
    if (ft_check_master(vars.check_map, &vars))
		return ( free_map(vars.map), free_map(vars.check_map), 1);
    ft_count(vars.check_map, &vars);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, vars.col * 50,
                               vars.row * 50, "Many Corp");
    init_image(&vars);
    zgag(&vars);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
    free_map(vars.map);
    free_map(vars.check_map);
    vars.map = NULL;
    vars.check_map = NULL;
    return (0);
}
