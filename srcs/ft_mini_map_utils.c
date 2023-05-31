/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/31 15:58:25 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_minimap_size(t_game *game)
{
	int	y;
	int	x;
	int	x_tmp;

	y = 0;
	x = 0;
	x_tmp = 0;
	while (game->parse.map[y])
	{
		while (game->parse.map[y][x])
			x++;
		if (x > x_tmp)
			x_tmp = x;
		y++;
		x = 0;
	}
	game->data.minimap_y = y * 10;
	game->data.minimap_x = x_tmp * 10;
}

void	ft_minimap_color_init(t_game *game)
{
	 game->data.mini_map_floor[0] = 200;
	 game->data.mini_map_floor[1] = 200;
	 game->data.mini_map_floor[2] = 150;
	 game->data.mini_map_floor[3] = 190;
	 game->data.mini_map_walls[0] = 250;
	 game->data.mini_map_walls[1] = 250;
	 game->data.mini_map_walls[2] = 250;
	 game->data.mini_map_walls[3] = 150;
     game->data.mini_map_color[0] = 100;
	 game->data.mini_map_color[1] = 100;
	 game->data.mini_map_color[2] = 250;
	 game->data.mini_map_color[3] = 150;
}
