/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    parcer_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:54:52 by kirilltruha       #+#    #+#             */
/*   Updated: 2021/02/23 16:47:47 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/file.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int	ft_size_array(int fd)
{
	int		i;
	char	c;

	i = 1;
	while(read(fd, c, 1))
	{
		if(c == '\n')
			i++;
	}
	return (i);
}

int	ft_parce_map(int fd)
{
	char **map;
	int	str;

	map = ft_calloc(((str = ft_parce_map(fd)) + 1), sizeof(char*));




}