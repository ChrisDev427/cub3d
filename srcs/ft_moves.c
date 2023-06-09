/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/09 14:55:33 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_mp_moves(t_game *game)
{
    int x;
    int y;

    x = game->mov.player_x;
    y = game->mov.player_y;

    if (game->mov.moves[0] == 'u' && game->parse.mapcpy[y -1][x] != '1')
        game->mov.player_y -= 1;
    else if (game->mov.moves[1] == 'l' && game->parse.mapcpy[y][x -1] != '1')
        game->mov.player_x -= 1;
    else if (game->mov.moves[2] == 'r' && game->parse.mapcpy[y][x +1] != '1')
        game->mov.player_x += 1;
    else if (game->mov.moves[3] == 'd' && game->parse.mapcpy[y +1][x] != '1')
        game->mov.player_y += 1;
}

void	trigo_direction(t_game *game, int speed, double radians, int reverse)
{
	int mov_playerx;
	int mov_playery;

	mov_playerx = (int)(speed * cos(radians));
	mov_playery = (int)(speed * cos(radians));
	game->mov.player_x += (mov_playerx * reverse);
	game->mov.player_y += (mov_playery * reverse);
}
void	trigo_rotation(t_game *game, int length, double radians)
{
	game->mov.endx = game->mov.center_x + (int)(length * cos(radians));
	game->mov.endy = game->mov.center_y + (int)(length * cos(radians));
}

static void ft_player_moves(t_game *game)
{
    int x;
    int y;
	int mov_playerx;
	int mov_playery;

	int	deplacement = 8; // vitesse de deplacement

    x = game->mov.player_x;
    y = game->mov.player_y;

    if (game->mov.moves[0] == 'u' && game->parse.mapcpy[y -1][x] != '1')
		trigo_direction(game, 1, game->mov.rad, 1);
    if (game->mov.moves[1] == 'l' && game->parse.mapcpy[y][x -1] != '1')
		trigo_direction(game, 1, game->mov.rad + M_PI / 2, -1);
    if (game->mov.moves[2] == 'r' && game->parse.mapcpy[y][x +1] != '1')
		trigo_direction(game, 1, game->mov.rad + M_PI / 2, 1);
    if (game->mov.moves[3] == 'd' && game->parse.mapcpy[y +1][x] != '1')
		trigo_direction(game, 1, game->mov.rad, -1);
	printf("pos player x = %d\n", game->mov.player_x);
	printf("pos player y = %d\n", game->mov.player_y);
}

void    ft_moves(t_game *game)
{
    ft_player_moves(game);
    ft_mp_moves(game);
}