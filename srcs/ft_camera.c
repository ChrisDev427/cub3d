/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 17:58:06 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//rotate to the left
void    ft_rotate_left(t_game *game)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = game->rc.dir_x;
    game->rc.dir_x = game->rc.dir_x * cos(ROT_SPEED) - game->rc.dir_y * sin(ROT_SPEED);
    game->rc.dir_y = oldDirX * sin(ROT_SPEED) + game->rc.dir_y * cos(ROT_SPEED);
    double oldPlaneX = game->rc.plane_x;
    game->rc.plane_x = game->rc.plane_x * cos(ROT_SPEED) - game->rc.plane_y * sin(ROT_SPEED);
    game->rc.plane_y = oldPlaneX * sin(ROT_SPEED) + game->rc.plane_y * cos(ROT_SPEED);
}
//rotate to the right
void    ft_rotate_right(t_game *game)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = game->rc.dir_x;
    game->rc.dir_x = game->rc.dir_x * cos(-ROT_SPEED) - game->rc.dir_y * sin(-ROT_SPEED);
    game->rc.dir_y = oldDirX * sin(-ROT_SPEED) + game->rc.dir_y * cos(-ROT_SPEED);
    double oldPlaneX = game->rc.plane_x;
    game->rc.plane_x = game->rc.plane_x * cos(-ROT_SPEED) - game->rc.plane_y * sin(-ROT_SPEED);
    game->rc.plane_y = oldPlaneX * sin(-ROT_SPEED) + game->rc.plane_y * cos(-ROT_SPEED);
}



void    ft_camera(t_game *game)
{
    if (game->camera[0] == 'l')
    {
        game->rad -= 0.01;
        if (game->rad < -M_PI)
        game->rad = M_PI;
		ft_rotate_right(game);
    }
    if (game->camera[1] == 'r')
    {
        game->rad += 0.01;
        if (game->rad > M_PI)
        game->rad = -M_PI;
		ft_rotate_left(game);
    }
}