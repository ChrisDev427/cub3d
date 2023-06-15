/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 12:53:51 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	trigo_direction(t_game *game, double speed, double radians, int reverse)
{
	double mov_playerx;
	double mov_playery;

	mov_playerx = (speed * cos(radians));
	mov_playery = (speed * sin(radians));
	game->fpos_x += (mov_playerx * reverse);
	game->fpos_y += (mov_playery * reverse);
}

static void    ft_up(t_game *game)
{
    // if ((game->mapcpy[(game->pp_y -1) /20][(game->pp_x +19) /20]
    //     != '1') && (game->mapcpy[(game->pp_y -1) /20][game->pp_x /20] != '1'))
    // {
        //game->pp_y -= 4;
        //game->fp_y -= 0.2;
		trigo_direction(game, 0.1, game->rad, -1);
    // }
}
static void    ft_down(t_game *game)
{
    // if ((game->mapcpy[(game->pp_y +20) /20][(game->pp_x +19) /20] != '1')
    //     && (game->mapcpy[(game->pp_y +20) /20][game->pp_x /20] != '1'))
    // {
        //game->pp_y += 4;
        //game->fp_y += 0.2;
		trigo_direction(game, 0.1, game->rad, 1);
    // }
}
static void    ft_right(t_game *game)
{
//     if ((game->mapcpy[game->pp_y  /20][(game->pp_x +20) /20] != '1')
//         && (game->mapcpy[(game->pp_y +19) /20][(game->pp_x +20) /20] != '1'))
//     {
        //game->pp_x += 4;
        //game->fp_x += 0.2;
		trigo_direction(game, 0.1, game->rad + M_PI / 2, -1);
    // }
}
static void    ft_left(t_game *game)
{
    // if ((game->mapcpy[(game->pp_y +19) /20][(game->pp_x -1) /20] != '1')
    //     && (game->mapcpy[(game->pp_y ) /20][(game->pp_x -1) /20] != '1'))
    // {
        //game->pp_x -= 4;
        //game->fp_x -= 0.2;
		trigo_direction(game, 0.1, game->rad + M_PI / 2, 1);
    // }
}
void ft_player_moves(t_game *game)
{
	game->ppos_x = (game->fpos_x * 20);
	game->ppos_y = (game->fpos_y * 20);

    if (game->moves[0] == 'u')
        ft_up(game);
    if (game->moves[3] == 'd')
        ft_down(game);
    if (game->moves[2] == 'r')
        ft_right(game);
    if (game->moves[1] == 'l')
        ft_left(game);
}

