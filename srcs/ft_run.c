/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 11:39:22 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    ft_run(t_game *game)
{
    // if (game->data.frame == 100)
    //     game->data.frame = 0;
    // game->data.frame++;

    ft_print_specs(game); 
	mlx_clear_window(game->win.mlx, game->win.win); // Efface la fenêtre
   	ft_print_floor_ceiling(game);
    ft_mini_map(game);

    ft_player_moves(game);
    ft_camera(game);
    
    ft_raycasting_test(game);
    
    // if (game->data.frame % 2 == 1)
	ft_title(game);
    mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.game_img.img, 0, 0);
	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, MP_POS_HEIGHT, MP_POS_WIDTH);
    
    return (0);
}