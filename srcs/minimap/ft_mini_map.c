/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/08 11:25:08 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static void	ft_print_minimap(t_game *game, int y, int x, int color)
// {
// 	int i = 0;
// 	int j = 0;
// 	int x_tmp;
// 	y *= MP_SIZE_LINES;
// 	x *= MP_SIZE_LINES;
// 	x_tmp = x;
// 	while (i < MP_SIZE_LINES)
// 	{
// 		while (j < MP_SIZE_LINES)
// 		{
// 			// ft_my_mlx_pixel_put(game, game->data.addr_mp, x, y, color);
// 			j++;
// 			x++;
// 		}
// 		i++;
// 		y++;
// 		x = x_tmp;
// 		j = 0;
// 	}

// }



static void	ft_print_back_ground(t_game *game)
{
	int x;
	int y;
	y = 0;
	x = 0;
	while (y < MP_HEIGHT)
	{
		while (x < MP_WIDTH)
		{
			if ((y < 4) || (y > 245) || (x < 4) || (x > 395))
				ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, 0x6C6C6C); // filling minimap border
			else
				ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, game->data.mp_bg_color);                                       // filling minimap back ground
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_mini_map(t_game *game)
{
	// int x;
	// int y;

	ft_print_back_ground(game);

	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, 35, 720);

	// y = 0;
	// x = 0;
	// while (game->parse.map[y])
	// {
	// 	while (game->parse.map[y][x])
	// 	{

	// 		// if (game->parse.map[y][x] == 'N' || game->parse.map[y][x] == 'S' || game->parse.map[y][x] == 'E' || game->parse.map[y][x] == 'W')
	// 		// 	ft_print_minimap(game, y, x, game->data.mp_walls_color);
	// 		// if (game->parse.map[y][x] == '1')
	// 		// 	ft_print_minimap(game, y, x, game->data.mp_walls_color);

	// 		x++;
	// 	}
	// 	y++;
	// 	x = 0;
	// }
	// mlx_put_image_to_window(game->win.mlx, game->win.win, game->data.minimap_img, 20, 20);

}
