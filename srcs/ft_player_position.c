/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:11:44 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/13 11:42:44 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_position(t_game *game, int y, int x, char dir)
{
    game->mov.player_y = y;
    game->mov.player_x = x;
    game->mov.pos_y = y;
    game->mov.pos_x = x;
    //put position to the center
    game->mov.pos_y += 0.5;
    game->mov.pos_x += 0.5;
    if (dir == 'N')
        game->mov.deg = 90;
    if (dir == 'S')
        game->mov.deg = 270;
    if (dir == 'E')
        game->mov.deg = 0;
    if (dir == 'W')
        game->mov.deg = 180;
    game->parse.mapcpy[y][x] = 'P';
    game->mov.rad = game->mov.deg * (M_PI/180);
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