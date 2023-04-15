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
	char	pos[2];
	char	**map;
	char	**Check_map;
	char	next;
	int		Perso_X;
	int		Perso_Y;
	int		Porte_X;
	int		Porte_Y;
	int		img_width;
	int		img_height;
	int		Count_Collect;
    int     col;
    int     row;
	int		step_count;
	int		x;
	int		y;
	int		o;
}				t_vars;

int ft_check_line(char **tab);
int ft_check_cpe(char **tab, t_vars *vars);
int ft_check_master(char **map, t_vars *vars);
int ftstrlen(char *str);
char **ft_maps(char *str, char **tab);
int compteur();
int	key_hook(int keycode, t_vars *vars);
int ft_count(char **tab, t_vars *vars);
void init_image(t_vars *vars);
void print_image(t_vars *vars, char c,int x,int y);
void	zgag(t_vars *vars);
int free_map(char **map);
int move_down(t_vars *vars);
int move_right(t_vars *vars);
int move_left(t_vars *vars);
int move_up(t_vars *vars);
char **ft_copy_map(char **tab);
char **ft_fd_init(char *str);
int	ft_valid_path(char **map, int i, int j, t_vars *vars);
int ft_check_ber(char *file);
int	ft_check_horizontal(char **tab, int i, int k);

//moi Yacine je tiens a remercier Ilona car elle m'a tout appris, a debugger mon code et en plus elle est trop belle vraiment merci ilona <3
                               

#endif 