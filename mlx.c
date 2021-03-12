/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:45:03 by kirill            #+#    #+#             */
/*   Updated: 2021/03/03 21:05:49 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include "cub3d.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int             main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int     x;
    int     y;
    int     i;
    int     j;
    int		fd;
    char    **map;

    fd = open("map.cub", O_RDONLY);
    map = map_maker(fd);
    /*mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
	&img.line_length, &img.endian);
    x = 0;
    y = 0;
    j = 0;*/
    i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    printf("%s\n", map[i]);
    /*while (map[i] != NULL)
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] == '0' && **map)
                x++;
            if (map[i][j] == 32 && **map)
                x++;
            if (map[i][j] == '1' && **map)
                my_mlx_pixel_put(&img, x++, y, 0xFFFFFF);
            j++;
        }
        y++;
        i++;
    }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);*/
    while(i >= 0)
    {
        free(map[i]);
        i--;
    }
    free(map);
	return (0);
}
