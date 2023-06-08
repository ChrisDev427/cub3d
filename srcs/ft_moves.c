/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/06 19:38:38 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_moves(t_game *game)
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