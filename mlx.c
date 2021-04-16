/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:45:03 by kirill            #+#    #+#             */
/*   Updated: 2021/03/28 16:57:28 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_M1/mlx.h"
#include "headers/keycode.h"
#include "headers/cub3d.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_mlx {
	void	    *mlx;
	void	    *mlx_win;
}               t_mlx;

typedef struct  s_img {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_img;

typedef struct  s_all {
	t_mlx       mlx;
	t_img       img;
	char		**map;
	int         x;
	int         y;
	int         xn;
	int         yn;
	int         m;
}               t_all;

void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int				put_pixel_sq(int m, int *w, int *h)
{
	int y;
	int x;
	int yn;
	int xn;
	
	y = *h;
	x = *w;
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
	*h = y;
	*w = x;
	return (0);
}

int				hook_key(int keycode, t_img *image)
{
 
	if (keycode == 0)
	{
		printf("blyaaaaa\n");
	
	}
	return (0);
}

t_img            ft_draw_img(t_all *all)
{
	t_img   img;
	t_mlx   mlx;
	char    **map;
	
	map = all->map;
	mlx = all->mlx;
	img.img = mlx_new_image(mlx.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	                                  &img.line_length, &img.endian);
	while (*map)
	{
		all->x = 0;
		while (**map)
		{
			if (**map == '0' && **map)
				put_pixel_sq(all->m, &all->x, &all->y);
			if (**map == 32 && **map)
				put_pixel_sq(all->m, &all->x, &all->y);
			if (**map == '1' && **map)
			{
				all->yn = all->y;
				while (all->y < all->yn + all->m)
				{
					all->xn = all->x;
					while (all->x < all->xn + all->m)
						my_mlx_pixel_put(&img, all->x++, all->y, 0xFFFFFF);
					all->y++;
					all->x = all->xn;
				}
				all->y = all->yn;
				all->x += all->m;
			}
			if (**map == 'N' || **map == 'S' || **map == 'W' || **map == 'E' && **map)
			{
				all->yn = all->y;
				while (all->y < all->yn + all->m)
				{
					all->xn = all->x;
					while (all->x < all->xn + all->m)
						my_mlx_pixel_put(&img, all->x++, all->y, 0x0000FF);
					all->y++;
					all->x = all->xn;
				}
				all->y = all->yn;
				all->x += all->m;
			}
			(*map)++;
		}
		all->y += all->m;
		(map)++;
	}
	return (img);
}

int             ft_mlx_init(t_all *all)
{
	t_mlx   mlx;
	t_img	img;
	
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 640, 480, "Hello world!");
	/*img.img = mlx_new_image(mlx.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	                             &img.line_length, &img.endian);
	while (*map)
	{
		all->x = 0;
		while (**map)
		{
			if (**map == '0' && **map)
				put_pixel_sq(all->m, &all->x, &all->y);
			if (**map == 32 && **map)
				put_pixel_sq(all->m, &all->x, &all->y);
			if (**map == '1' && **map)
			{
				all->yn = all->y;
				while (all->y < all->yn + all->m)
				{
					all->xn = all->x;
					while (all->x < all->xn + all->m)
						my_mlx_pixel_put(&img, all->x++, all->y, 0xFFFFFF);
					all->y++;
					all->x = all->xn;
				}
				all->y = all->yn;
				all->x += all->m;
			}
			if (**map == 'N' || **map == 'S' || **map == 'W' || **map == 'E' && **map)
			{
				all->yn = all->y;
				while (all->y < all->yn + all->m)
				{
					all->xn = all->x;
					while (all->x < all->xn + all->m)
						my_mlx_pixel_put(&img, all->x++, all->y, 0x0000FF);
					all->y++;
					all->x = all->xn;
				}
				all->y = all->yn;
				all->x += all->m;
			}
			(*map)++;
		}
		all->y += all->m;
		(map)++;
	}*/
	//img = ft_draw_img(all);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 1L<<2, hook_key, &img);
	mlx_loop(mlx.mlx);
	return (0);

}

int             ft_init(char **map)
{
	t_all   all;
	
	all.map = map;
	all.x = 0;
	all.y = 0;
	all.m = 16;
	ft_mlx_init(&all);
	return (0);
}

int             main(int argc, char **argv)
{
    char    **map;
    int     i;
    
    if (argc == 2)
		map = map_maker(argv[1]);
    else
    {
    	printf("No map\n");
	    return (0);
    }
    ft_init(map);
	i = 0;
    while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}
