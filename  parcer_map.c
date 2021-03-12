/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    parcer_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:54:52 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/03/01 20:17:55 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_size_array(int fd)
{
	int		i;
	char	buf[1];

	i = 1;
	while(read(fd, buf, 1))
	{
		if(buf[0] == '\n')
			i++;
	}
	return (i);
}

char	**map_maker(int fd)
{
	int     i;
	char    **map;
	char	*line;
	
	i = 0;
	map = calloc((ft_size_array(fd) + 1), sizeof(char*));
	while(get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
        printf("%s\n", map[i]);
        printf("%s\n", line);
		free(line);
		i++;
	}
	map[i++] = ft_strdup(line);
    printf("%s\n", map[i]);
	free(line);
	line = NULL;
	/*while(i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);*/
	return (map);
}

int main(void)
{
    int fd;

    fd = open("map.cub", O_RDONLY);

    map_maker(fd);
}
