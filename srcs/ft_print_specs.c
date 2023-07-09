/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:01:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/08 18:07:41 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_print_specs(t_game *game)
{
        system("clear");
        printf("float_pos_x = [%f] - ipos_x = %d - pixel_player_x = %d\n", game->fpos_x, game->ipos_x, game->ppos_x);
        printf("float_pos_y = [%f] - ipos_y = %d - pixel_player_y = %d\n", game->fpos_y, game->ipos_y, game->ppos_y);
        printf("--------------------------------------------------------------\n");
        printf("rad =            [%f]\n", game->rad);
        printf("dir_x =          [%f]\n", game->rc.dir_x);
        printf("dir_y =          [%f]\n", game->rc.dir_y);
        printf("--------------------------------------------------------------\n");
        printf("map_x =          [%d]\n", game->rc.map_x);
        printf("map_y =          [%d]\n", game->rc.map_y);
        printf("--------------------------------------------------------------\n");
        printf("plane_x =        [%f]\n", game->rc.plane_x);
        printf("plane_y =        [%f]\n", game->rc.plane_y);
        printf("--------------------------------------------------------------\n");
        printf("ray_dir_x =      [%f]\n", game->rc.ray_dir_x);
        printf("ray_dir_y =      [%f]\n", game->rc.ray_dir_y);
        printf("--------------------------------------------------------------\n");
        printf("delta_dist_x =   [%f]\n", game->rc.delta_dist_x);
        printf("delta_dist_y =   [%f]\n", game->rc.delta_dist_y);
        printf("--------------------------------------------------------------\n");
        printf("side_dist_x =    [%f]\n", game->rc.side_dist_x);
        printf("side_dist_y =    [%f]\n", game->rc.side_dist_y);
        printf("--------------------------------------------------------------\n");
        printf("ray_x =          [%d]\n", game->rc.ray_x);
        printf("camera_x =       [%f]\n", game->rc.camera_x);
        printf("perp_wall_dist = [%f]\n\n", game->rc.perp_wall_dist);
        printf("--------------------------------------------------------------\n");
        printf("rot_speed =  [%s]-[%f]\n", game->state, game->rc.rot_speed);
        printf("mov_speed =  [%s]-[%f]\n", game->state, game->rc.move_speed);
        printf("side =  [%d]\n", game->rc.side);
}
