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



typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*perso;
    void	*wall;
    void	*collect;
    void	*flor;
    void	*door;
	char	*addr;
    int     col;
    int     row;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}				t_vars;


int ft_check_line(char **tab);
int ft_check_cpe(char **tab);
int ft_check_master(char **map);
int ftstrlen(char *str);
char **ft_maps(char *str, char **tab);
int compteur();
int	key_hook(int keycode, t_vars *vars);
int ft_count(char **tab, t_vars *vars);
void init_image(t_vars *vars);
void Print_image(char **tab);


#endif