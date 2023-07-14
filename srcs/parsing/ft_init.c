/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:44:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/14 20:30:42 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init(t_game *game)
{
	game->win.mlx = mlx_init();
	game->win.win = mlx_new_window(game->win.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"THE BEST CUB3D YOU EVER SEEN ;o)");
	game->data.frame = 0;
	game->camera[0] = 0;
	game->camera[1] = 0;
	game->moves[0] = 0;
	game->moves[1] = 0;
	game->moves[2] = 0;
	game->moves[3] = 0;
	ft_minimap_init(game);
}
