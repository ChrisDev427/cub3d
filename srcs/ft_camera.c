/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/16 14:03:42 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//rotate to the left
void    ft_rotate_left(t_game *game)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = game->rc.dir_x;
    game->rc.dir_x = game->rc.dir_x * cos(game->rc.rot_speed) - game->rc.dir_y * sin(game->rc.rot_speed);
    game->rc.dir_y = oldDirX * sin(game->rc.rot_speed) + game->rc.dir_y * cos(game->rc.rot_speed);
    double oldPlaneX = game->rc.plane_x;
    game->rc.plane_x = game->rc.plane_x * cos(game->rc.rot_speed) - game->rc.plane_y * sin(game->rc.rot_speed);
    game->rc.plane_y = oldPlaneX * sin(game->rc.rot_speed) + game->rc.plane_y * cos(game->rc.rot_speed);
}
//rotate to the right
void    ft_rotate_right(t_game *game)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = game->rc.dir_x;
    game->rc.dir_x = game->rc.dir_x * cos(-game->rc.rot_speed) - game->rc.dir_y * sin(-game->rc.rot_speed);
    game->rc.dir_y = oldDirX * sin(-game->rc.rot_speed) + game->rc.dir_y * cos(-game->rc.rot_speed);
    double oldPlaneX = game->rc.plane_x;
    game->rc.plane_x = game->rc.plane_x * cos(-game->rc.rot_speed) - game->rc.plane_y * sin(-game->rc.rot_speed);
    game->rc.plane_y = oldPlaneX * sin(-game->rc.rot_speed) + game->rc.plane_y * cos(-game->rc.rot_speed);
}



void    ft_camera(t_game *game)
{
    if (game->camera[0] == 'l')
    {
        game->rad += game->rc.rot_speed;
        if (game->rad > M_PI)
        game->rad = -M_PI;
		ft_rotate_right(game);
    }
    if (game->camera[1] == 'r')
    {
        game->rad -= game->rc.rot_speed;
        if (game->rad < -M_PI)
        game->rad = M_PI;
		ft_rotate_left(game);
    }
}