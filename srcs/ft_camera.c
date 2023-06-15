/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 13:29:54 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//rotate to the left
void    ft_rotate_left(t_game *game)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = game->rc.dir_x;
    game->rc.dir_x = game->rc.dir_x * cos(game->rad) - game->rc.dir_y * sin(game->rad);
    game->rc.dir_y = oldDirX * sin(game->rad) + game->rc.dir_y * cos(game->rad);
    double oldPlaneX = game->rc.plane_x;
    game->rc.plane_x = game->rc.plane_x * cos(game->rad) - game->rc.plane_y * sin(game->rad);
    game->rc.plane_y = oldPlaneX * sin(game->rad) + game->rc.plane_y * cos(game->rad);
}
//rotate to the right
void    ft_rotate_right(t_game *game)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = game->rc.dir_x;
    game->rc.dir_x = game->rc.dir_x * cos(-game->rad) - game->rc.dir_y * sin(-game->rad);
    game->rc.dir_y = oldDirX * sin(-game->rad) + game->rc.dir_y * cos(-game->rad);
    double oldPlaneX = game->rc.plane_x;
    game->rc.plane_x = game->rc.plane_x * cos(-game->rad) - game->rc.plane_y * sin(-game->rad);
    game->rc.plane_y = oldPlaneX * sin(-game->rad) + game->rc.plane_y * cos(-game->rad);
}



void    ft_camera(t_game *game)
{
    if (game->camera[0] == 'l')
    {
        game->rad += 0.005;
        if (game->rad > M_PI)
            game->rad = -M_PI;
        ft_rotate_left(game);
    }
    if (game->camera[1] == 'r')
    {
        game->rad -= 0.005;
        if (game->rad < -M_PI)
            game->rad = M_PI;
        ft_rotate_right(game);
    }
}