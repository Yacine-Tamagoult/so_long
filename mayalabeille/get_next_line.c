/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:01:19 by soleil            #+#    #+#             */
/*   Updated: 2023/04/17 22:40:41 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_alloc(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		ret;
	int		luffy;

	luffy = BUFFER_SIZE;
	if (luffy == 1)
		luffy = 10;
	buff = malloc(sizeof(char) * (luffy + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_strchr(str, '\n') && ret)
	{
		ret = read(fd, buff, luffy);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*l;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	l = ft_alloc(str);
	str = ft_jumpline(str);
	return (l);
}
