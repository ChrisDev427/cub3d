/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/15 13:19:25 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_run(t_game *game)
{
	mlx_clear_window(game->win.mlx, game->win.win);
	ft_camera(game);
	ft_raycasting(game);
	ft_speed(game);
	ft_player_moves(game);
	ft_mini_map(game);
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		game->image.game_img.img, 0, 0);
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		game->image.minimap.img, MP_POS_WIDTH, MP_POS_HEIGHT);
	return (0);
}
