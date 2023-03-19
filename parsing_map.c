#include "so_long.h"



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
	// topNbot = 0;
	// while(topNbot < k)
	// {
	// 	if(tab[i][topNbot] != '1')
	// 		return (1);
	// 	topNbot++;
	// }
	return (0);
}



int ft_valid_path(char **tab,int Y, int X, int Collect)
{
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	static int c = 0;
	printf("Bnjour je suis collect : %d\n",Collect);
	
	if(tab[Y][X] == 'C')
		c++;
	printf("Bnjour je suis c : %d\n",c);


	if(tab[Y][X] == 'E')
	{
		return(1);
	}
	

	tab[Y][X] = 'V';
	
	int i = 0;
	while(i < 4)
	{
		int NY = Y + dy[i];
		int NX = X + dx[i];

		if(tab[NY][NX] == '0' ||tab[NY][NX] == 'E' || tab[NY][NX] == 'C')
		{
			if(ft_valid_path(tab,NY,NX,Collect))
			{
				if(c != Collect)
					return(1);
				return(1);

			}
				
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
	printf("je suis Temp %d\n", temp);
    while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			j++;
		}
	printf("je suis j %d\n", j);

		if(temp != j)
            return (1);
        j = 0;
		i++;
	}
    return (0);
}


int ft_check_cpe(char **tab)
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
			}
			if(tab[i][j] == 'E')
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	if(p != 1 && e != 1 && c < 1)
		return(1);
		
	
	if(ft_valid_path(tab,Y,X,c) == 0)
	{
		return (1);
	}

	return (0);

}

int ft_check_master(char **map)
{
	
    if(ft_check_line(map))
    {
        printf("aaaaa\n");
		
    }
	else if(ft_check_square(map))
	{
		printf("bbbbbb\n");
		
	}
	else if(ft_check_wall(map))
	{
		printf("cccccc\n");
	}
	else if(ft_check_cpe(map) == 1)
	{
		printf("dddddd\n");
	}

	return (0);
}