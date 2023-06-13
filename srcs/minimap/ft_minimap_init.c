/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/13 14:01:01 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_color_assign(t_game *game)
{
	game->mp_data.mini_map_bg[0] = BG_COL_A;
	game->mp_data.mini_map_bg[1] = BG_COL_R;
	game->mp_data.mini_map_bg[2] = BG_COL_G;
	game->mp_data.mini_map_bg[3] = BG_COL_B;
	game->mp_data.mini_map_floor[0] = FL_COL_A;
	game->mp_data.mini_map_floor[1] = FL_COL_R;
	game->mp_data.mini_map_floor[2] = FL_COL_G;
	game->mp_data.mini_map_floor[3] = FL_COL_B;
	game->mp_data.mini_map_walls[0] = WL_COL_A;
	game->mp_data.mini_map_walls[1] = WL_COL_R;
	game->mp_data.mini_map_walls[2] = WL_COL_G;
	game->mp_data.mini_map_walls[3] = WL_COL_B;
	game->mp_data.mini_map_player[0] = PL_COL_A;
	game->mp_data.mini_map_player[1] = PL_COL_R;
	game->mp_data.mini_map_player[2] = PL_COL_G;
	game->mp_data.mini_map_player[3] = PL_COL_B;
}

static void	ft_color_init(t_game *game)
{
	game->mp_data.mp_floor_color = ft_color_to_int(game->mp_data.mini_map_floor);
	game->mp_data.mp_walls_color = ft_color_to_int(game->mp_data.mini_map_walls);
	game->mp_data.mp_bg_color = ft_color_to_int(game->mp_data.mini_map_bg);
	game->mp_data.mp_player_color = ft_color_to_int(game->mp_data.mini_map_player);
}

void	ft_minimap_init(t_game *game)
{
	ft_color_assign(game);
	ft_color_init(game);
}
