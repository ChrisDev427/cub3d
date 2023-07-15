/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:07:07 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/15 07:43:32 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_images(t_game *game)
{
	game->image.game_img.img = mlx_new_image(game->win.mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	game->image.game_img.addr = mlx_get_data_addr(game->image.game_img.img,
			&game->image.game_img.bits_per_pixel,
			&game->image.game_img.line_length, &game->image.game_img.endian);
	game->image.minimap.img = mlx_new_image(game->win.mlx,
			MP_WIDTH, MP_HEIGHT);
	game->image.minimap.addr = mlx_get_data_addr(game->image.minimap.img,
			&game->image.minimap.bits_per_pixel,
			&game->image.minimap.line_length, &game->image.minimap.endian);
}
