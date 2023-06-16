/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:11:44 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/16 11:18:29 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_position(t_game *game, int x, int y)
{
    game->ipos_y = y;
    game->ipos_x = x;
    game->ppos_y = y * 20;
    game->ppos_x = x * 20;
    game->fpos_y = y + 0.5;
    game->fpos_x = x + 0.5;
    game->mapcpy[y][x] = '0';
}

static void ft_direction(t_game *game, char dir)
{
    if (dir == 'N')
    {
        game->rad = M_PI_2;
        game->rc.dir_x = 0;
        game->rc.dir_y = -1;
        game->rc.plane_x = -0.66;
        game->rc.plane_y = 0;
    }
    if (dir == 'S')
    {
        game->rad = -M_PI_2;
        game->rc.dir_x = 0;
        game->rc.dir_y = 1;
        game->rc.plane_x = 0.66;
        game->rc.plane_y = 0;
    }
    if (dir == 'E')
    {
        game->rad = 0;
        game->rc.dir_x = 1;
        game->rc.dir_y = 0;
        game->rc.plane_x = 0;
        game->rc.plane_y = -0.66;
    }
    if (dir == 'W')
    {
        game->rad = M_PI;
        game->rc.dir_x = -1;
        game->rc.dir_y = 0;
        game->rc.plane_x = 0;
        game->rc.plane_y = 0.66;
    }
}

void    ft_position_direction(t_game *game)
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
                {
                    ft_direction(game, game->mapcpy[y][x]);
                    ft_position(game, x, y);
                }
        y++;
    }
}