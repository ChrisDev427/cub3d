/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/16 11:12:07 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// //move forward if no wall in front of you
//     if (keyDown(SDLK_UP))
//     {
//       if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
//     }
//     //move backwards if no wall behind you
//     if (keyDown(SDLK_DOWN))
//     {
//       if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//     }
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
    // if(game->mapcpy[(int)game->fpos_x + (int)game->rc.dir_x * (int)MOVE_SPEED][(int)game->fpos_y] != '1') 
    // if(game->mapcpy[(int)game->fpos_x][(int)game->fpos_y + (int)game->rc.dir_y * (int)MOVE_SPEED] != '1')
    if ((game->mapcpy[(game->ppos_y -1) /20][(game->ppos_x +19) /20]
        != '1') && (game->mapcpy[(game->ppos_y -1) /20][game->ppos_x /20] != '1'))
    {
        game->fpos_x += game->rc.dir_x * MOVE_SPEED;
        game->fpos_y += game->rc.dir_y * MOVE_SPEED;
        //game->pp_y -= 4;
        //game->fp_y -= 0.2;
		trigo_direction(game, 0.1, game->rad, 1);
    }
}
static void    ft_down(t_game *game)
{

    if ((game->mapcpy[(game->ppos_y +21) /20][(game->ppos_x +21) /20] != '1')
        && (game->mapcpy[(game->ppos_y +20) /20][game->ppos_x /20] != '1'))
    {
        game->fpos_x -= game->rc.dir_x * MOVE_SPEED;
        game->fpos_y -= game->rc.dir_y * MOVE_SPEED;
        //game->pp_y += 4;
        //game->fp_y += 0.2;
		trigo_direction(game, 0.1, game->rad, -1);
    }
}
static void    ft_left(t_game *game)
{
    if ((game->mapcpy[(game->ppos_y +19) /20][(game->ppos_x -1) /20] != '1')
        && (game->mapcpy[(game->ppos_y ) /20][(game->ppos_x -1) /20] != '1'))
    {

        game->ppos_x -= 4;
        game->fpos_x -= 0.2;
		trigo_direction(game, 0.1, game->rad - M_PI_2, -1);
    }
}
static void    ft_right(t_game *game)
{
    if ((game->mapcpy[game->ppos_y  /20][(game->ppos_x +20) /20] != '1')
        && (game->mapcpy[(game->ppos_y +19) /20][(game->ppos_x +20) /20] != '1'))
    {
        game->ppos_x += 4;
        game->fpos_x += 0.2;
		trigo_direction(game, 0.1, game->rad - M_PI_2, 1);
    }
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

