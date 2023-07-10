/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:07:07 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/08 22:48:33 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void    ft_init_images(t_game *game)
{
        // New image pour affichage du jeu
        game->image.game_img.img = mlx_new_image(game->win.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
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
        game->image.title_img.img = mlx_new_image(game->win.mlx, SCREEN_WIDTH, 40);
        // recup de l'adresse de title_img
	game->image.title_img.addr = mlx_get_data_addr(game->image.title_img.img,
        &game->image.title_img.bits_per_pixel, &game->image.title_img.line_length, &game->image.title_img.endian);
}

void	ft_init_sprites(t_game *game)
{
	game->rc.texwidth = 64;
	game->rc.texheight = 64;
	game->image.north.img= mlx_xpm_file_to_image(game->win.mlx, "/Users/axelfernandez/ecole42/cursus42/cub3d/sprites/sun.xpm", &game->rc.texwidth, &game->rc.texheight);
	game->image.west.img = mlx_xpm_file_to_image(game->win.mlx, "/Users/axelfernandez/ecole42/cursus42/cub3d/sprites/earth.xpm", &game->rc.texwidth, &game->rc.texheight);
	game->image.east.img = mlx_xpm_file_to_image(game->win.mlx, "/Users/axelfernandez/ecole42/cursus42/cub3d/sprites/mars.xpm", &game->rc.texwidth, &game->rc.texheight);
	game->image.south.img = mlx_xpm_file_to_image(game->win.mlx, "/Users/axelfernandez/ecole42/cursus42/cub3d/sprites/moon.xpm", &game->rc.texwidth, &game->rc.texheight);
}