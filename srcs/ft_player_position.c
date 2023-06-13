/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:11:44 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/13 14:02:59 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_position(t_game *game, int y, int x, char dir)
{
    game->player_y = y;
    game->player_x = x;
    game->pp_y = y *20;
    game->pp_x = x *20;
    game->fp_y = y;
    game->fp_x = x;
    //put position to the center
    game->fp_y += 0.5;
    game->fp_x += 0.5;
    if (dir == 'N')
        game->deg = 90;
    if (dir == 'S')
        game->deg = 270;
    if (dir == 'E')
        game->deg = 0;
    if (dir == 'W')
        game->deg = 180;
    game->mapcpy[y][x] = '0';
    game->rad = game->deg * (M_PI/180);

}

void    ft_player_position(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (game->mapcpy[y])
    {
        while(game->mapcpy[y][x])
        {
            if (game->mapcpy[y][x] == 'N')
                ft_position(game, y, x, 'N');
            if (game->mapcpy[y][x] == 'S')
                ft_position(game, y, x, 'S');
            if (game->mapcpy[y][x] == 'E')
                ft_position(game, y, x, 'E');
            if (game->mapcpy[y][x] == 'W')
                ft_position(game, y, x, 'W');
            x++;
        }
        x = 0;
        y++;
    }
}