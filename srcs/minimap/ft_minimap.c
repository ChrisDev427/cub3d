/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/12 22:52:00 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_axis(t_game *game)
{
	int		needle_length = 50; // Longueur de l'aiguille

	game->mp_data.end_needle_x = (int)game->mov.player_x + (int)(needle_length * cos(game->mov.rad));
	game->mp_data.end_needle_y = (int)game->mov.player_y + (int)(needle_length * sin(game->mov.rad));

	int	dx = game->mp_data.end_needle_x - (int)game->mov.player_x;
	int	dy = game->mp_data.end_needle_y - (int)game->mov.player_y;
	int	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float	x_increment = (float)dx / (float)steps;
	float	y_increment = (float)dy / (float)steps;

	game->mov.pos_x = (float)game->mov.player_x;
	game->mov.pos_y = (float)game->mov.player_y;

	for (int i = 0; i <= steps; i++)
	{
		game->mov.pos_x += x_increment;
		game->mov.pos_y += y_increment;
		ft_my_mlx_pixel_put(&game->image.minimap_img, game->mov.pos_x, game->mov.pos_y, 0x123224);
	}
}
static void	ft_draw_player(t_game *game, int y, int x, int color)
{
	int i = 0;
	int j = 0;
	int x_tmp;

	x_tmp = x;
	while (i < 15)
	{
		while (j < 15)
		{
			//if (game->mp_data.player_radius_border[i][j] == '1')
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

static void	ft_print_minimap(t_game *game)
{
	int x = 0;
	int y = 0;
	int i;
	int j;
	i = game->mov.p_player_x - 150 + 10;
	j = game->mov.p_player_y - 150 + 10;

	while (y < MP_HEIGHT)
	{
		i = game->mov.p_player_x - 150 + 10;
		x = 0;
		while (x < MP_WIDTH)
		{
			// int tile_x = game->mov.p_player_x / 15;
            // int game->mov.p_player_y = game->mov.p_player_y / 15;

            if (game->parse.mapcpy[j / 15][i / 15] == '0' || game->parse.mapcpy[j / 15][i / 15] == 'P')
                ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, 0xFFFFFF);
            else if (game->parse.mapcpy[j / 15][i / 15] == '1')
                ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, 0x435533);
            else if (game->parse.mapcpy[j / 15][i / 15] == '|')
                ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, 0x435533 / 2);

            x++;
            i++;
        }
        y++;
        j++;
	}
	// for (int k = 0; k < 15; k++)
	// {
	// 	int l = 0;
	// 	while (l < 15)
	// 	{
	// 		ft_my_mlx_pixel_put(&game->image.minimap_img, 150 + l, 150 + k, 0x436345);
	// 		l++;
	// 	}
	// }
}


void	ft_mini_map(t_game *game)
{
	mlx_clear_window(game->win.mlx, game->win.win);
	//ft_print_back_ground(game);
	ft_print_minimap(game);
	ft_draw_axis(game);
	ft_draw_player(game, (MP_HEIGHT / 2) -10, (MP_WIDTH / 2) -10, game->mp_data.mp_player_color);
	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, 35, 35);
}
