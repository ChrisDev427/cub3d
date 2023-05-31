/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:07:07 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/31 17:29:02 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void    ft_init_minimap(t_game *game)
{
    ft_minimap_size(game);
    ft_minimap_color_init(game);
    game->data.minimap_img = mlx_new_image(game->win.mlx, game->data.minimap_x,
        game->data.minimap_y);
	game->data.img_data = mlx_get_data_addr(game->data.minimap_img,
        &game->data.bits_per_pixel, &game->data.size_line, &game->data.endian);
}