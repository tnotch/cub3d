/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:45:03 by kirill            #+#    #+#             */
/*   Updated: 2021/03/14 17:36:50 by kirilltruha      ###   ########.fr       */
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

int				hook_key(int keycode, t_data *img)
{
	printf("bye\n");
	return (0);
}

int				put_pixel_sq(char *map, int mas)
{
	return (0);
}

int             main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int     x;
    int     y;
	int     xn;
    int     yn;
    int     i;
    int     j;
	int		m;
    int		fd;
    char    **map;

	map = map_maker(argv[1]);
    mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
	&img.line_length, &img.endian);
    x = 0;
    y = 0;
    j = 0;
    i = 0;
	m = 16;
    while (*map)
    {
        x = 0;
		j = 0;
		while (**map)
        {
            if (**map == '0' && **map)
			{
				yn = y;
				while (y < yn + m)
				{
					xn = x;
					while (x < xn + m)
                		x++;
					y++;
					x = xn;
				}
				y = yn;
				x += m;
			}
            if (**map == 32 && **map)
			{
				yn = y;
				while (y < yn + m)
				{
					xn = x;
					while (x < xn + m)
                		x++;
					y++;
					x = xn;
				}
				y = yn;
				x += m;
			}
            if (**map == '1' && **map)
			{
				yn = y;
				while (y < yn + m)
				{
					xn = x;
					while (x < xn + m)
                		my_mlx_pixel_put(&img, x++, y, 0xFFFFFF);
					y++;
					x = xn;
				}
				y = yn;
				x += m;
			}
			if (**map == 'N' || **map == 'S' || **map == 'W' || **map == 'E' && **map)
			{
				yn = y;
				while (y < yn + m)
				{
					xn = x;
					while (x < xn + m)
                		my_mlx_pixel_put(&img, x++, y, 0x0000FF);
					y++;
					x = xn;
				}
				y = yn;
				x += m;
			}
            (*map)++;
        }
        y += m;
        (map)++;
    }
	mlx_hook(mlx_win, 0, 1L<<0, hook_key, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	i = 0;
    while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}
