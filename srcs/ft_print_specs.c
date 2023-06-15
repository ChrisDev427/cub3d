/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:01:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 14:26:56 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_print_specs(t_game *game)
{
    // if (game->moves[0] == 'u' || game->moves[1] == 'l' || game->moves[2] == 'r'
    //     || game->moves[3] == 'd' || game->camera[0] == 'l' || game->camera[1] == 'r')
    // {
        system("clear");
        printf("float_pos_x = [%f] - ipos_x = %d - pixel_player_x = %d\n", game->fpos_x, game->ipos_x, game->ppos_x);
        printf("float_pos_y = [%f] - ipos_y = %d - pixel_player_y = %d\n", game->fpos_y, game->ipos_y, game->ppos_y);
        printf("rad =            [%f]\n", game->rad);
        printf("dir_x =          [%f]\n", game->rc.dir_x);
        printf("dir_y =          [%f]\n\n", game->rc.dir_y);

        printf("map_x =          [%d]\n", game->rc.map_x);
        printf("map_y =          [%d]\n\n", game->rc.map_y);

        printf("plane_x =        [%f]\n", game->rc.plane_x);
        printf("plane_y =        [%f]\n", game->rc.plane_y);

        printf("ray_dir_x =      [%f]\n", game->rc.ray_dir_x);
        printf("ray_dir_y =      [%f]\n\n", game->rc.ray_dir_y);

        printf("delta_dist_x =   [%f]\n", game->rc.delta_dist_x);
        printf("delta_dist_y =   [%f]\n\n", game->rc.delta_dist_y);

        printf("side_dist_x =    [%f]\n", game->rc.side_dist_x);
        printf("side_dist_y =    [%f]\n\n", game->rc.side_dist_y);

        printf("ray_x =          [%d]\n", game->rc.ray_x);
        printf("camera_x =       [%f]\n", game->rc.camera_x);
        printf("perp_wall_dist = [%f]\n", game->rc.perp_wall_dist);
        puts("");

    // }
}