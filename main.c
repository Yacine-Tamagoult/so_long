/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:56:35 by soleil            #+#    #+#             */
/*   Updated: 2023/04/16 00:43:58 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ftstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_copy_map(char **tab)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	while (tab[i])
		i++;
	copy = (char **)malloc((i + 1) * sizeof(char *));
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
			free (copy);
			return (NULL);
		}
		j++;
	}
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
		map[j] = malloc(sizeof(char) * (ftstrlen(tab[j]) + 1));
		while (tab[j][k])
		{
			map[j][k] = tab[j][k];
			k++;
		}
		map[j][k] = 0;
		j--;
	}
	k = 0;
	while (str[k])
	{
		map[i][k] = str[k];
		k++;
	}
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
		return (0);
	return (1);
}

char	**ft_fd_init(char *file)
{	
	int		i;
	char	*str;
	char	**tab;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
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
	return (tab);
}

int	main(int ac, char **av)
{	
	t_vars	vars;
	int		j;
	int		k;

	k = 0;
	j = 0;
	vars.map = ft_copy_map (ft_fd_init(av[1]));
	vars.Check_map = ft_copy_map (vars.map);
	if (ft_check_ber(av[1]))
	{
		printf ("Error");
		return (1);
	}
	if (ft_check_master(vars.Check_map, &vars))
		return (1);
	ft_count (vars.Check_map, &vars);
	vars.mlx = mlx_init ();
	vars.win = mlx_new_window (vars.mlx, vars.col * 50,
			vars.row * 50, "Many Corp");
	init_image (&vars);
	zgag (&vars);
	mlx_key_hook (vars.win, key_hook, &vars);
	mlx_loop (vars.mlx);
	return (0);
}
