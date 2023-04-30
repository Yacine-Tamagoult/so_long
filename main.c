/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:56:35 by soleil            #+#    #+#             */
/*   Updated: 2023/04/30 23:07:42 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(char **tab)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	copy = (char **)malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	copy[i] = NULL;
	j = -1;
	while (++j < i)
	{
		copy[j] = strdup(tab[j]);
		if (!copy[j])
		{
			while (j-- > 0)
				free(copy[j]);
			return (free(copy), NULL);
		}
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
		map[j] = strdup(tab[j]);
		free(tab[j]);
		j--;
	}
	if (j < 0)
		free (tab);
	k = -1;
	while (str[++k])
		map[i][k] = str[k];
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
	int		fd;

	i = 0;
	tab = NULL;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
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

int	main(int ac, char **av)
{
	t_vars	vars;
	char	**tab;

	if (ac != 2)
		return (1);
	if (ft_check_ber(av[1]))
		return (printf("Error\n"), 1);
	memset(&vars, 0, sizeof(vars));
	tab = ft_fd_init(av[1]);
	if (!tab)
		return (printf("Error\n"), 1);
	vars.map = ft_copy_map(tab);
	if (!vars.map)
		return (printf("error"), 1);
	vars.check_map = ft_copy_map(vars.map);
	free_map(tab);
	if (ft_check_master(vars.check_map, &vars))
		return (free_map(vars.map), free_map(vars.check_map), 1);
	ft_count(vars.check_map, &vars);
	place(&vars);
	return (0);
}
