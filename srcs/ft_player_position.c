/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:11:44 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 10:20:51 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_position(t_game *game, int y, int x, char dir)
{
    game->ipos_y = y;
    game->ipos_x = x;
    game->ppos_y = y *20;
    game->ppos_x = x *20;
    game->fpos_y = y + 0.5;
    game->fpos_x = x + 0.5;
    if (dir == 'N')
    {
        game->rad = M_PI/2;
        game->rc.dir_x = 0;
        game->rc.dir_y = 1;
    }
    if (dir == 'S')
    {
        game->rad = -M_PI/2;
        game->rc.dir_x = 0;
        game->rc.dir_y = -1;
    }
    if (dir == 'E')
    {
        game->rad = 0;
        game->rc.dir_x = 1;
        game->rc.dir_y = 0;
    }
    if (dir == 'W')
    {
        game->rad = M_PI;
        game->rc.dir_x = -1;
        game->rc.dir_y = 0;
    }
    game->mapcpy[y][x] = '0';    
}

void    ft_player_position(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (game->mapcpy[y])
    {
        x = 0;
        while(game->mapcpy[y][x++])
            if (game->mapcpy[y][x] == 'N' || game->mapcpy[y][x] == 'S'
                || game->mapcpy[y][x] == 'E' || game->mapcpy[y][x] == 'W')
                ft_position(game, y, x, game->mapcpy[y][x]);
        y++;
    }
}