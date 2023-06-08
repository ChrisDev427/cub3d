/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:11:44 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/06 17:45:37 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_position(t_game *game, int y, int x, char dir)
{
    game->mov.player_y = y;
    game->mov.player_x = x;
    game->mov.mp_pos_y = y;
    game->mov.mp_pos_x = x;
    if (dir == 'N')
        game->mov.degrees = 0;
    if (dir == 'S')
        game->mov.degrees = 180;
    if (dir == 'E')
        game->mov.degrees = 90;
    if (dir == 'W')
        game->mov.degrees = 270;
    game->parse.mapcpy[y][x] = 'P';
}

void    ft_player_position(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (game->parse.mapcpy[y])
    {
        while(game->parse.mapcpy[y][x])
        {
            if (game->parse.mapcpy[y][x] == 'N')
                ft_position(game, y, x, 'N');
            if (game->parse.mapcpy[y][x] == 'S')
                ft_position(game, y, x, 'S');
            if (game->parse.mapcpy[y][x] == 'E')
                ft_position(game, y, x, 'E');
            if (game->parse.mapcpy[y][x] == 'W')
                ft_position(game, y, x, 'W');
            x++;
        }
        x = 0;
        y++;
    }
}