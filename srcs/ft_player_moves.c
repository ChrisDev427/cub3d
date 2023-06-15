/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/14 19:06:14 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    ft_up(t_game *game)
{
    if ((game->mapcpy[(game->ppos_y -1) /20][(game->ppos_x +19) /20]
        != '1') && (game->mapcpy[(game->ppos_y -1) /20][game->ppos_x /20] != '1'))
    {
        game->ppos_y -= 4;
        game->fpos_y -= 0.2;   
        
    }
}
static void    ft_down(t_game *game)
{
    if ((game->mapcpy[(game->ppos_y +20) /20][(game->ppos_x +19) /20] != '1')
        && (game->mapcpy[(game->ppos_y +20) /20][game->ppos_x /20] != '1'))
    {
        game->ppos_y += 4;
        game->fpos_y += 0.2;
          

    }
}
static void    ft_right(t_game *game)
{
    if ((game->mapcpy[game->ppos_y  /20][(game->ppos_x +20) /20] != '1')
        && (game->mapcpy[(game->ppos_y +19) /20][(game->ppos_x +20) /20] != '1'))
    {
        game->ppos_x += 4;
        game->fpos_x += 0.2;
          

    }
}
static void    ft_left(t_game *game)
{
    if ((game->mapcpy[(game->ppos_y +19) /20][(game->ppos_x -1) /20] != '1')
        && (game->mapcpy[(game->ppos_y ) /20][(game->ppos_x -1) /20] != '1'))
    {
        game->ppos_x -= 4;
        game->fpos_x -= 0.2;
       

    }
}
void ft_player_moves(t_game *game)
{
    if (game->moves[0] == 'u')
        ft_up(game);
    if (game->moves[3] == 'd')
        ft_down(game);
    if (game->moves[2] == 'r')
        ft_right(game);
    if (game->moves[1] == 'l')
        ft_left(game);
}

