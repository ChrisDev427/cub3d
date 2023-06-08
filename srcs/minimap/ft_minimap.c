/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/08 17:17:24 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_axis(t_game *game)
{
	int		needle_length = 50; // Longueur de l'aiguille

	game->mp_data.end_needle_x = game->mp_data.start_needle_x + (int)(needle_length * cos(game->mov.rad));
	game->mp_data.end_needle_y = game->mp_data.start_needle_y + (int)(needle_length * sin(game->mov.rad));

	int	dx = game->mp_data.end_needle_x - game->mp_data.start_needle_x;
	int	dy = game->mp_data.end_needle_y - game->mp_data.start_needle_y;
	int	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float	x_increment = (float)dx / (float)steps;
	float	y_increment = (float)dy / (float)steps;

	game->mov.pos_x = game->mp_data.start_needle_x;
	game->mov.pos_y = game->mp_data.start_needle_y;

	for (int i = 0; i <= steps; i++)
	{
		game->mov.pos_x += x_increment;
		game->mov.pos_y += y_increment;
		ft_my_mlx_pixel_put(&game->image.minimap_img, game->mov.pos_x, game->mov.pos_y, 0xFFFFFF);
	}
}
static void	ft_draw_player(t_game *game, int y, int x, int color)
{
	int i = 0;
	int j = 0;
	int x_tmp;

	x_tmp = x;
	while (i <= MP_SIZE_LINES)
	{
		while (j <= MP_SIZE_LINES)
		{
			if (game->mp_data.player_radius_border[i][j] == '1')
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

static void	ft_print_minimap(t_game *game, int y, int x)
{
	ft_init_variables(game, &x, &y);
	while (y)
	{
		while (x < game->mp_data.x_tmp +11)
		{
			if (game->parse.mapcpy[y][x] == '0' || game->parse.mapcpy[y][x] == 'P')
				ft_draw_walls_floor(game, game->mp_data.y_mp,
					game->mp_data.x_mp, game->mp_data.mp_floor_color);
			else if (game->parse.mapcpy[y][x] == '1')
				ft_draw_walls_floor(game, game->mp_data.y_mp,
					game->mp_data.x_mp, game->mp_data.mp_walls_color);
			game->mp_data.x_mp += 9;
			x++;
		}
		y++;
		game->mp_data.y_mp += 9;
		if (y == (game->mp_data.y_tmp +11) && x == (game->mp_data.x_tmp +11))
			break ;
		x = game->mp_data.x_tmp -10;
		game->mp_data.x_mp = 5;
	}
}


void	ft_mini_map(t_game *game)
{
	ft_print_back_ground(game);
	ft_print_minimap(game, game->mov.player_y, game->mov.player_x);
	ft_draw_axis(game);
	ft_draw_player(game, 95, 95, game->mp_data.mp_player_color);
	// mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, 35, 765);
}
