#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "mayalabeille/get_next_line.h"
# include <stdio.h>

int ft_check_line(char **tab);
int ft_check_cpe(char **tab);
int ft_check_master(char **map);
int ftstrlen(char *str);
char **ft_maps(char *str, char **tab);



#endif