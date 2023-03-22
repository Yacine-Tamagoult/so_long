#include "so_long.h"



int	key_hook(int keycode, t_vars *vars)
{
	static int i = 0;
	if (keycode == 119 || keycode == 115 |keycode == 97 |keycode == 100)
	{
		printf("Move :%d\n",i);
		i++;
	}
		
}

