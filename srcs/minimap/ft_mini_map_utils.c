/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/05 14:06:25 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	ft_minimap_size(t_game *game)
// {
// 	int	y;
// 	int	x;
// 	int	x_tmp;

// 	y = 0;
// 	x = 0;
// 	x_tmp = 0;
// 	while (game->parse.map[y])
// 	{
// 		while (game->parse.map[y][x])
// 			x++;
// 		if (x > x_tmp)
// 			x_tmp = x;
// 		y++;
// 		x = 0;
// 	}
// 	game->data.minimap_y = y * 10;
// 	game->data.minimap_x = x_tmp * 10;
// }

void	ft_minimap_color_init(t_game *game)
{
	 game->data.mini_map_bg[0] = BG_COL_A;
	 game->data.mini_map_bg[1] = BG_COL_R;
	 game->data.mini_map_bg[2] = BG_COL_G;
	 game->data.mini_map_bg[3] = BG_COL_B;
	 
	 game->data.mini_map_floor[0] = FL_COL_A;
	 game->data.mini_map_floor[1] = FL_COL_R;
	 game->data.mini_map_floor[2] = FL_COL_G;
	 game->data.mini_map_floor[3] = FL_COL_B;

	 game->data.mini_map_walls[0] = WL_COL_A;
	 game->data.mini_map_walls[1] = WL_COL_R;
	 game->data.mini_map_walls[2] = WL_COL_G;
	 game->data.mini_map_walls[3] = WL_COL_B;

	 game->data.mini_map_player[0] = PL_COL_A;
	 game->data.mini_map_player[1] = PL_COL_R;
	 game->data.mini_map_player[2] = PL_COL_G;
	 game->data.mini_map_player[3] = PL_COL_B;


	 game->data.mp_floor_color = ft_color_to_int(game->data.mini_map_floor);
	 game->data.mp_walls_color = ft_color_to_int(game->data.mini_map_walls);
	 game->data.mp_bg_color = ft_color_to_int(game->data.mini_map_bg);
	 game->data.mp_player_color= ft_color_to_int(game->data.mini_map_player);
	
}
