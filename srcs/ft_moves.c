/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/12 19:58:22 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void ft_mp_moves(t_game *game)
// {
//     int x;
//     int y;

//     x = game->mov.player_x;
//     y = game->mov.player_y;

//     if (game->mov.moves[0] == 'u' && game->parse.mapcpy[y -1][x] != '1')
//     {
//         game->mov.player_y -= 1;
//     }
//     else if (game->mov.moves[1] == 'l' && game->parse.mapcpy[y][x -1] != '1')
//     {
//         game->mov.player_x -= 1;
//     }
//     else if (game->mov.moves[2] == 'r' && game->parse.mapcpy[y][x +1] != '1')
//     {
//         game->mov.player_x += 1;
//     }
//     else if (game->mov.moves[3] == 'd' && game->parse.mapcpy[y +1][x] != '1')
//     {
//         game->mov.player_y += 1;
//     }
// }

static void ft_player_moves(t_game *game)
{
    if (game->mov.moves[0] == 'u' && game->parse.mapcpy[(game->mov.p_player_y -1) /20][game->mov.p_player_x / 20] != '1')
    {
        game->mov.p_player_y -= 2;
        game->mov.pos_y -= 0.1;

    }
    if (game->mov.moves[1] == 'l' && game->parse.mapcpy[game->mov.p_player_y /20][(game->mov.p_player_x -1) /20] != '1')
    {
        game->mov.p_player_x -= 2;
        game->mov.pos_x -= 0.1;

    }
    if (game->mov.moves[2] == 'r' && game->parse.mapcpy[game->mov.p_player_y /20][(game->mov.p_player_x +20) /20] != '1')
    {
        game->mov.p_player_x += 2;
        game->mov.pos_x += 0.1;

    }
    if (game->mov.moves[3] == 'd' && game->parse.mapcpy[(game->mov.p_player_y +20) /20][game->mov.p_player_x /20] != '1')
    {
        game->mov.p_player_y += 2;
        game->mov.pos_y += 0.1;

    }

}


void    ft_moves(t_game *game)
{
    ft_player_moves(game);
    // ft_mp_moves(game);
    
}