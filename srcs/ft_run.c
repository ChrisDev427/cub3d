/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/12 19:54:01 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    ft_run(t_game *game)
{
  
    if (game->data.frame == 100)
        game->data.frame = 0;
    game->data.frame++;

    // if (game->data.frame % 6 == 1)
	mlx_clear_window(game->win.mlx, game->win.win); // Efface la fenêtre
    ft_camera(game);
   	ft_print_floor_ceiling(game);

    ft_mini_map(game);
    // if (game->data.frame % 2 == 1)
        ft_moves(game);
	ft_title(game);
	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, MP_POS_HEIGHT, MP_POS_WIDTH);
    
    ft_print_specs(game); 
    return (0);
}