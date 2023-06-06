/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/06 13:14:51 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_draw_player(t_game *game, int y, int x, int color)
{
	int i = 0;
	int j = 0;
	int x_tmp;
	// y *= MP_SIZE_LINES;
	// x *= MP_SIZE_LINES;
	x_tmp = x;
	while (i < MP_SIZE_LINES)
	{
		while (j < MP_SIZE_LINES)
		{
			ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, color);
			j++;
			x++;
		}
		i++;
		y++;
		x = x_tmp;
		j = 0;
	}
	
}
static void	ft_draw_walls_floor(t_game *game, int y, int x, int color)
{
	int i = 0;
	int j = 0;
	int x_tmp;
	// y *= MP_SIZE_LINES;
	// x *= MP_SIZE_LINES;
	x_tmp = x;
	while (i < MP_SIZE_LINES)
	{
		while (j < MP_SIZE_LINES)
		{
			ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, color);
			j++;
			x++;
		}
		i++;
		y++;
		x = x_tmp;
		j = 0;
	}
	
}



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
			if ((y < 4) || (y > 195) || (x < 4) || (x > 195))
				ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, 0x6C6C6C); // filling minimap border
			else
				ft_my_mlx_pixel_put(&game->image.minimap_img, x, y,
				game->data.mp_bg_color);                                       // filling minimap back ground
			x++;
		}
		y++;
		x = 0;
	}
}
static void	ft_print_minimap(t_game *game, int y, int x)
{
	
	// printf("y = %d\n", y);
	// printf("x = %d\n", x);
	int	y_tmp;
	int	x_tmp;

	int	y_mp = 6;
	int	x_mp = 6;


	y_tmp = y;
	x_tmp = x;
	y -= 10;
	x -= 10;
	// printf("y = %d\n", y);
	// printf("x = %d\n", x);
	
	

	while (y)
	{
		while (x < x_tmp +11)
		{
			if (game->parse.mapcpy[y][x] == '0' || game->parse.mapcpy[y][x] == 'S')
				ft_draw_walls_floor(game, y_mp,  x_mp, game->data.mp_floor_color);

			if (game->parse.mapcpy[y][x] == '1')
				ft_draw_walls_floor(game, y_mp,  x_mp, game->data.mp_walls_color);

			// printf("%c", game->parse.mapcpy[y][x]);
			x_mp += 9;
			x++;
		}
		puts("");
		y++;
		y_mp += 9;
		if (y == (y_tmp +11) && x == (x_tmp +11))
			break ;
			
		x = x_tmp -10;
		x_mp = 6;
	}
	ft_draw_player(game, 96,  96, game->data.mp_player_color);
}

void	ft_mini_map(t_game *game)
{
	// int x;
	// int y;

	// y = 0;
	// x = 0;
	ft_print_back_ground(game);
	ft_print_minimap(game, game->mov.mp_pos_y, game->mov.mp_pos_x);

	// while (game->parse.mapcpy[y])
	// {
	// 	while (game->parse.mapcpy[y][x])
	// 	{
	// 		if (game->mov.mp_pos_y == y && game->mov.mp_pos_x == x)
	// 		{
	// 			printf("y = %d\n", y);
	// 			printf("x = %d\n", x);

	// 		}
	// 			// ft_print_minimap(game, y, x, game->data.mp_player_color);
	// 		// ft_print_minimap(game, game->mov.mp_pos_y, game->mov.mp_pos_x, game->data.mp_player_color);
	// 		// if (game->parse.mapcpy[y][x] == 'N' || game->parse.mapcpy[y][x] == 'S'
	// 		// 	|| game->parse.mapcpy[y][x] == 'E' || game->parse.mapcpy[y][x] == 'W')
	// 		// 	ft_print_minimap(game, y, x, game->data.mp_player_color);
	// 		// if (game->parse.mapcpy[y][x] == '1')
	// 		// 	ft_print_minimap(game, y, x, game->data.mp_walls_color);
			
	// 		x++;
	// 	}
	// 	y++;
	// 	x = 0;
	// }
	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, 35, 720);
	// mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, 20, 20);

}
