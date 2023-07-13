/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 10:00:48 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    ft_run(t_game *game)
{
	mlx_clear_window(game->win.mlx, game->win.win); // Efface la fenêtre
    ft_camera(game);
    ft_raycasting(game);
    ft_speed(game);
    ft_player_moves(game);
    ft_print_specs(game);
    ft_mini_map(game);
    mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.game_img.img, 0, 0);
	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, MP_POS_HEIGHT, MP_POS_WIDTH);
    mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.title_img.img, 0, SCREEN_HEIGHT - 35);
	mlx_string_put(game->win.mlx, game->win.win, 10, SCREEN_HEIGHT - 25, 0x00CF10, "chmassa/axfernan cub3D_42_project june 2023");
    return (0);
}