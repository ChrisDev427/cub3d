/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/09 14:10:19 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    ft_run(t_game *game)
{
  
    if (game->data.frame == 200)
        game->data.frame = 0;
    game->data.frame++;

    // ft_print_floor_ceiling(game);
    // if (game->data.frame % 6 == 1)
	mlx_clear_window(game->win.mlx, game->win.win); // Efface la fenêtre
    ft_camera(game);
   	// ft_print_floor_ceiling(game);

    ft_mini_map(game);
    if (game->data.frame % 8 == 1)
        ft_moves(game);
    // printf("%f\n", game->mov.degrees);
    // printf("%d\n", game->data.frame);
    
	ft_title(game);
    ft_print_specs(game); 

	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, 225, 100);
    
    return (0);
}