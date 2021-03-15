/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    parcer_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:54:52 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/03/13 19:35:47 by kirilltruha      ###   ########.fr       */
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

char	**map_maker(char *file_name)
{
	int     i;
	int		fd;
	char    **map;
	char	*line;
	const char	*file;
	
	i = 0;
	file = file_name;
	fd = open(file, O_RDONLY);
	map = calloc((ft_size_array(fd) + 1), sizeof(char*));
	fd = open(file, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map[i] = ft_strdup(line);
	free(line);
	line = NULL;
	return (map);
}