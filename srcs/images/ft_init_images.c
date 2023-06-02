/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:07:07 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/02 16:46:52 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void    ft_init_images(t_game *game)
{
        // New image pour affichage du jeu
        game->image.game_img.img = mlx_new_image(game->win.mlx, WIDTH, HEIGHT);
        // recup de l'adresse de l'image game_img
        game->image.game_img.addr = mlx_get_data_addr(game->image.game_img.img,         
        &game->image.game_img.bits_per_pixel, &game->image.game_img.line_length, &game->image.game_img.endian);
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
        // New image pour affichage de la minimap
        game->image.minimap_img.img = mlx_new_image(game->win.mlx, MP_WIDTH, MP_HEIGHT); 
        // recup de l'adresse de l'image minimap_img
	game->image.minimap_img.addr = mlx_get_data_addr(game->image.minimap_img.img,
        &game->image.minimap_img.bits_per_pixel, &game->image.minimap_img.line_length, &game->image.minimap_img.endian);

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
        // New image pour title_img
        game->image.title_img.img = mlx_new_image(game->win.mlx, TITLE_WIDTH, TITLE_HEIGHT); 
        // recup de l'adresse de title_img
	game->image.title_img.addr = mlx_get_data_addr(game->image.title_img.img,
        &game->image.title_img.bits_per_pixel, &game->image.title_img.line_length, &game->image.title_img.endian);
}