/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/16 11:20:24 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//rotate to the left
void    ft_rotate_left(t_game *game)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = game->rc.dir_x;
    game->rc.dir_x = game->rc.dir_x * cos(0.02) - game->rc.dir_y * sin(0.02);
    game->rc.dir_y = oldDirX * sin(0.02) + game->rc.dir_y * cos(0.02);
    double oldPlaneX = game->rc.plane_x;
    game->rc.plane_x = game->rc.plane_x * cos(0.02) - game->rc.plane_y * sin(0.02);
    game->rc.plane_y = oldPlaneX * sin(0.02) + game->rc.plane_y * cos(0.02);
}
//rotate to the right
void    ft_rotate_right(t_game *game)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = game->rc.dir_x;
    game->rc.dir_x = game->rc.dir_x * cos(-0.02) - game->rc.dir_y * sin(-0.02);
    game->rc.dir_y = oldDirX * sin(-0.02) + game->rc.dir_y * cos(-0.02);
    double oldPlaneX = game->rc.plane_x;
    game->rc.plane_x = game->rc.plane_x * cos(-0.02) - game->rc.plane_y * sin(-0.02);
    game->rc.plane_y = oldPlaneX * sin(-0.02) + game->rc.plane_y * cos(-0.02);
}



void    ft_camera(t_game *game)
{
    if (game->camera[0] == 'l')
    {
        game->rad += 0.02;
        if (game->rad > M_PI)
        game->rad = -M_PI;
		ft_rotate_right(game);
    }
    if (game->camera[1] == 'r')
    {
        game->rad -= 0.02;
        if (game->rad < -M_PI)
        game->rad = M_PI;
		ft_rotate_left(game);
    }
}