/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/14 12:25:30 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_go_straight(t_game *game)
{
	if (game->rc.dir_x >= 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.4)]
		[(int)(game->fpos_x + 0.5)] != '1')
			game->fpos_x += game->rc.dir_x * game->rc.move_speed;
	if (game->rc.dir_x < 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.4)]
		[(int)(game->fpos_x - 0.5)] != '1')
			game->fpos_x += game->rc.dir_x * game->rc.move_speed;
	if (game->rc.dir_y >= 0)
		if (game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.5)]
		[(int)(game->fpos_x + 0.4)] != '1')
			game->fpos_y += game->rc.dir_y * game->rc.move_speed;
	if (game->rc.dir_y < 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)]
		!= '1' && game->mapcpy[(int)(game->fpos_y - 0.5)]
		[(int)(game->fpos_x + 0.4)] != '1')
			game->fpos_y += game->rc.dir_y * game->rc.move_speed;
}

static void	ft_go_back(t_game *game)
{
	if (game->rc.dir_x >= 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.4)]
		[(int)(game->fpos_x - 0.5)] != '1')
			game->fpos_x -= game->rc.dir_x * game->rc.move_speed;
	if (game->rc.dir_x < 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.4)]
		[(int)(game->fpos_x + 0.5)] != '1')
			game->fpos_x -= game->rc.dir_x * game->rc.move_speed;
	if (game->rc.dir_y >= 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)]
		!= '1' && game->mapcpy[(int)(game->fpos_y - 0.5)]
		[(int)(game->fpos_x + 0.4)] != '1')
			game->fpos_y -= game->rc.dir_y * game->rc.move_speed;
	if (game->rc.dir_y < 0)
		if (game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.5)]
		[(int)(game->fpos_x + 0.4)] != '1')
			game->fpos_y -= game->rc.dir_y * game->rc.move_speed;
}

void	ft_player_moves(t_game *game)
{
	game->ppos_x = (game->fpos_x * 20);
	game->ppos_y = (game->fpos_y * 20);
	game->ipos_x = game->fpos_x;
	game->ipos_y = game->fpos_y;
	if (game->moves[0] == 'u')
		ft_go_straight(game);
	if (game->moves[3] == 'd')
		ft_go_back(game);
	if (game->moves[2] == 'r')
		ft_go_right(game);
	if (game->moves[1] == 'l')
		ft_go_left(game);
}
