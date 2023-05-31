/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/31 18:06:00 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	ft_print_map(t_game *game, int y, int x)
// {
// 	int i = 0;
// 	int j = 0;
// 	int x_tmp = x;
// 	while (i < 100)
// 	{
// 		while (j < 100)
// 		{
// 			game->data.pixel_offset = (y * game->data.size_line) + (x * (game->data.bits_per_pixel / 8));
// 			game->data.img_data[game->data.pixel_offset] = game->data.mini_map_color[0];
// 			game->data.img_data[game->data.pixel_offset + 1] = game->data.mini_map_color[1];
// 			game->data.img_data[game->data.pixel_offset + 2] = game->data.mini_map_color[2];
// 			game->data.img_data[game->data.pixel_offset + 3] = game->data.mini_map_color[3];
// 			j++;
// 			x++;
// 		}
// 		i++;
// 		y++;
// 		x = x_tmp;
// 		j = 0;
// 	}
// }

static void	ft_print_floor(t_game *game, int y, int x)
{
	int i = 0;
	int j = 0;
	int x_tmp = x;
	while (i < 10)
	{
		while (j < 10)
		{
			game->data.pixel_offset = (y * game->data.size_line) + (x * (game->data.bits_per_pixel / 8));
			game->data.img_data[game->data.pixel_offset] = game->data.mini_map_floor[0];
			game->data.img_data[game->data.pixel_offset + 1] = game->data.mini_map_floor[1];
			game->data.img_data[game->data.pixel_offset + 2] = game->data.mini_map_floor[2];
			game->data.img_data[game->data.pixel_offset + 3] = game->data.mini_map_floor[3];
			j++;
			x++;
		}
		i++;
		y++;
		x = x_tmp;
		j = 0;
	}
	
}

static void	ft_print_walls(t_game *game, int y, int x)
{
	int i = 0;
	int j = 0;
	int x_tmp = x;
	while (i < 10)
	{
		while (j < 10)
		{
			game->data.pixel_offset = (y * game->data.size_line) + (x * (game->data.bits_per_pixel / 8));
			game->data.img_data[game->data.pixel_offset] = game->data.mini_map_walls[0];
			game->data.img_data[game->data.pixel_offset + 1] = game->data.mini_map_walls[1];
			game->data.img_data[game->data.pixel_offset + 2] = game->data.mini_map_walls[2];
			game->data.img_data[game->data.pixel_offset + 3] = game->data.mini_map_walls[3];
				j++;
			x++;
		}
		i++;
		y++;
		x = x_tmp;
		j = 0;
	}
	
}

// static void	my_mlx_pixel_put(void *img_ptr, int x, int y, int color)
// {
	
// }

void	ft_mini_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (game->parse.map[y])
	{
		while (game->parse.map[y][x])
		{
			// if (game->parse.map[y][x] == ' ')
			// 	ft_print_map(game, y, x);
			if (game->parse.map[y][x] == '0')
				ft_print_floor(game, y*10, x*10);
			if (game->parse.map[y][x] == '1')
				ft_print_walls(game, y*10, x*10);
			
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(game->win.mlx, game->win.win, game->data.minimap_img, 20, 20);




	// while (y < game->data.minimap_y)
	// {
	// 	while (x < game->data.minimap_x)
	// 	{
	// 		game->data.pixel_offset = (y * game->data.size_line) + (x * (game->data.bits_per_pixel / 8));
	// 		game->data.img_data[game->data.pixel_offset] = game->data.mini_map_floor[0];
	// 		game->data.img_data[game->data.pixel_offset + 1] = game->data.mini_map_floor[1];
	// 		game->data.img_data[game->data.pixel_offset + 2] = game->data.mini_map_floor[2];
	// 		game->data.img_data[game->data.pixel_offset + 3] = game->data.mini_map_floor[3];
	// 		x++;
	// 	}
	// 	y++;
	// 	x = 0;
	// }
}
