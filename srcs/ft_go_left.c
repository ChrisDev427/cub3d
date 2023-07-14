/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:45:02 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/14 11:54:12 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_moves_a(t_game *game)
{
	if (game->rc.dir_x >= 0 && game->rc.dir_y < 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x
			- 0.5)] != '1')
			game->fpos_x += (game->rc.dir_x -1) * game->rc.move_speed;
	if (game->rc.dir_y < 0 && game->rc.dir_x >= 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)]
		!= '1' && game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x
			+ 0.4)] != '1')
			game->fpos_y -= (game->rc.dir_y +1) * game->rc.move_speed;
	if (game->rc.dir_x < 0 && game->rc.dir_y < 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x
			- 0.5)] != '1')
			game->fpos_x -= (game->rc.dir_x +1) * game->rc.move_speed;
	if (game->rc.dir_y < 0 && game->rc.dir_x < 0)
		if (game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x
			+ 0.4)] != '1')
			game->fpos_y += (game->rc.dir_y +1) * game->rc.move_speed;
}

static void	ft_moves_b(t_game *game)
{
	if (game->rc.dir_x < 0 && game->rc.dir_y >= 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x
			+ 0.5)] != '1')
			game->fpos_x += (game->rc.dir_x +1) * game->rc.move_speed;
	if (game->rc.dir_y >= 0 && game->rc.dir_x < 0)
		if (game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x
			+ 0.4)] != '1')
			game->fpos_y -= (game->rc.dir_y -1) * game->rc.move_speed;
	if (game->rc.dir_x >= 0 && game->rc.dir_y >= 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)]
		!= '1' && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x
			+ 0.5)] != '1')
			game->fpos_x -= (game->rc.dir_x -1) * game->rc.move_speed;
	if (game->rc.dir_y >= 0 && game->rc.dir_x >= 0)
		if (game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)]
		!= '1' && game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x
			+ 0.4)] != '1')
			game->fpos_y += (game->rc.dir_y -1) * game->rc.move_speed;
}

void	ft_go_left(t_game *game)
{
	ft_moves_a(game);
	ft_moves_b(game);
}
