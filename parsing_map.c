#include "so_long.h"

int free_map(char **map)
{
	int j;

	j = 0;
	while(map[j])
	{
		free(map[j]);
		j++;
	}
	free(map);
	return (1);
}

int ft_check_parasit(char **tab)
{
	int i = 0;
	int j;
	int searchPara = 0;
   
    while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			if(tab[i][j] != 'C' && tab[i][j] != 'E' && tab[i][j] != 'P' && tab[i][j] != '1' && tab[i][j] != '0')
			{
				searchPara++;
			}
			j++;
		}
		i++;
	}
	if(searchPara != 0)
		return(1);
	return (0);
}
  
int ft_check_square(char **tab)
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
	if(i == j)
			return(1);
		return (0);
}

int ft_check_wall(char **tab)
{
	int i = 0;
	int j;
	int topNbot = 0;
	int k = ftstrlen(tab[0]);
	
	while(topNbot < k)
	{
		if(tab[i][topNbot] != '1')
			return (1);
		topNbot++;
	}
	while(tab[i])
	{
		j = 0;
		if(tab[i][j] != '1')
			return(1);
		while(tab[i][j])
		{
			j++;
		}
		if(tab[i][j - 1] != '1')
			return(1);
        j = 0;
		i++;
	}
	 topNbot = 0;
	 while(topNbot < k)
	 {
	 	if(tab[i - 1][topNbot] != '1')
	 		return (1);
	 	topNbot++;
	 }
	return (0);
}

int ft_valid_path(char **tab,int Y, int X, int Collect, t_vars *vars)
{
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	static int c = 0;
	
	if(tab[Y][X] == 'C')
		c++;
	if(tab[Y][X] == 'E' && c == vars->Count_Collect)
		return(1);
	int j;
	j = 0;
	tab[Y][X] = 'V';
	int i = 0;
	while(i < 4)
	{
		int NY = Y + dy[i];
		int NX = X + dx[i];
		if(tab[NY][NX] == '0' ||tab[NY][NX] == 'E' || tab[NY][NX] == 'C')
			if(ft_valid_path(tab,NY,NX,Collect,vars))
			{
				if(c != Collect)
					return(1);
				return(1);
			}
		i++;
	}
	return (0);
}

int ft_check_line(char **tab)
{
    int i = 0;
	int j;
    int temp;
    temp = ftstrlen(tab[0]);
    while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			j++;
		}
		if(temp != j)
            return (1);
        j = 0;
		i++;
	}
    return (0);
} 


int ft_check_cpe(char **tab, t_vars *vars)
{
	int i = 0;
	int j;
	int c = 0;
	int p = 0;
	int e = 0;
	int X = 0;
	int Y = 0;

	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			if(tab[i][j] == 'C')
				c++;
			if(tab[i][j] == 'P')
			{
				p++;
				X = j;
				Y = i;
				vars->Perso_X = j * 50;
				vars->Perso_Y = i * 50;
			}
			if(tab[i][j] == 'E')
			{	
				vars->Porte_X = j * 50;
				vars->Porte_Y = i * 50;
				e++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	vars->Count_Collect = c;
	if(p != 1 || e != 1 || c != 1)
		return(1);
	else if(ft_valid_path(tab,Y,X,c,vars) == 0)
	 	return (1);
	return (0);
}


int ft_check_master(char **map, t_vars *vars)
{
    if(ft_check_line(map))
	{
		printf("2\n");
		return (1);
	} 
	else if(ft_check_parasit(map))
	 {
		printf("3\n");
		return (1);
	 }
	else if(ft_check_square(map))
	{
		printf("4\n");
		return(1);
	}
	else if(ft_check_wall(map))
	{
		printf("5\n");
		return (1);
	}
	else if(ft_check_cpe(map,vars))
	{
		printf("6\n");
		return(1);
	}
	
	return (0);
}



