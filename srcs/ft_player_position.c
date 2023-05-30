/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:11:44 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/30 19:24:00 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_north_pos(t_game *game, int y, int x, char dir)
{
    game->mov.player_y = y;
    game->mov.player_x = x;
    if (dir == 'N')
        game->mov.degrees = 0;
    if (dir == 'S')
        game->mov.degrees = 180;
    if (dir == 'E')
        game->mov.degrees = 90;
    if (dir == 'W')
        game->mov.degrees = 270;
}

void    ft_player_position(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (game->parse.map[y])
    {
        while(game->parse.map[y][x])
        {
            if (game->parse.map[y][x] == 'N')
                ft_north_pos(game, y, x, 'N');
            if (game->parse.map[y][x] == 'S')
                ft_north_pos(game, y, x, 'S');
            if (game->parse.map[y][x] == 'E')
                ft_north_pos(game, y, x, 'E');
            if (game->parse.map[y][x] == 'W')
                ft_north_pos(game, y, x, 'W');
            x++;
        }
        x = 0;
        y++;
    }
}