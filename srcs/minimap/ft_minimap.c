/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:12:59 by chris             #+#    #+#             */
/*   Updated: 2023/07/13 17:51:07 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_axis(t_game *game, double pos, int needle_length)
{
	game->end_needle_x = game->ppos_x + (int)(needle_length
			* cos(-game->rad - pos));
	game->end_needle_y = game->ppos_y + (int)(needle_length
			* sin(-game->rad - pos));
	game->dx = game->end_needle_x - game->ppos_x;
	game->dy = game->end_needle_y - game->ppos_y;
	if (abs(game->dx) > abs(game->dy))
		game->steps = abs(game->dx);
	else
		game->steps = abs(game->dy);
	game->x_increment = (float)game->dx / (float)game->steps;
	game->y_increment = (float)game->dy / (float)game->steps;
	game->pos_x = (MP_WIDTH / 2);
	game->pos_y = (MP_HEIGHT / 2);
	game->i = 0;
	while (game->i <= game->steps)
	{
		game->pos_x += game->x_increment;
		game->pos_y += game->y_increment;
		ft_my_pixel_put(&game->image.minimap,
			game->pos_x, game->pos_y, 0xFF0000);
		game->i++;
	}
}

static void	ft_print_minimap(t_game *game)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	y = game->ppos_y - (MP_HEIGHT / 2);
	while (i < MP_HEIGHT)
	{
		j = 0;
		x = game->ppos_x - (MP_WIDTH / 2);
		while (j < MP_WIDTH)
		{
			if (game->mapcpy[y / 20][x / 20] == '1')
				ft_my_pixel_put(&game->image.minimap, j, i, game->mp.walls_cl);
			if (game->mapcpy[y / 20][x / 20] == '|')
				ft_my_pixel_put(&game->image.minimap, j, i, game->mp.over_cl);
			x++;
			j++;
		}
		i++;
		y++;
	}
}

void	ft_mini_map(t_game *game)
{
	ft_print_back_ground(game);
	ft_print_minimap(game);
	ft_draw_axis(game, -M_PI / 4, 30);
	ft_draw_axis(game, -M_PI / 4 * -1, 30);
	ft_draw_player(game, MP_HEIGHT / 2 -10, MP_WIDTH / 2 -10, game->mp.pl_cl);
}
