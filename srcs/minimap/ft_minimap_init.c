/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/11 11:30:05 by chris            ###   ########.fr       */
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
void	ft_init_radius_player(t_game *game)
{
	// game->mp_data.y_tmp = *y;
	// game->mp_data.x_tmp = *x;
	// *y -= 20;
	// *x -= 20;
	// game->mp_data.y_mp = 5;
	// game->mp_data.x_mp = 5;
	game->mp_data.player_radius_border[0] =  "0000001111111000000";
	game->mp_data.player_radius_border[1] =  "0000111111111110000";
	game->mp_data.player_radius_border[2] =  "0001111111111111000";
	game->mp_data.player_radius_border[3] =  "0011111111111111100";
	game->mp_data.player_radius_border[4] =  "0111111111111111110";
	game->mp_data.player_radius_border[5] =  "0111111111111111110";
	game->mp_data.player_radius_border[6] =  "1111111111111111111";
	game->mp_data.player_radius_border[7] =  "1111111111111111111";
	game->mp_data.player_radius_border[8] =  "1111111111111111111";
	game->mp_data.player_radius_border[9] =  "1111111111111111111";
	game->mp_data.player_radius_border[10] = "1111111111111111111";
	game->mp_data.player_radius_border[11] = "1111111111111111111";
	game->mp_data.player_radius_border[12] = "1111111111111111111";
	game->mp_data.player_radius_border[13] = "1111111111111111111";
	game->mp_data.player_radius_border[14] = "0111111111111111110";
	game->mp_data.player_radius_border[15] = "0111111111111111110";
	game->mp_data.player_radius_border[16] = "0011111111111111100";
	game->mp_data.player_radius_border[17] = "0001111111111111000";
	game->mp_data.player_radius_border[18] = "0000111111111110000";
	game->mp_data.player_radius_border[19] = "0000001111111000000";
}

void	ft_minimap_init(t_game *game)
{
	// int	fd;

	ft_color_assign(game);
	ft_color_init(game);
// 	fd = open("mp_map_border.txt", O_RDONLY);
// 	game->mp_data.minimap_border = ft_get_map("mp_map_border.txt", game->mp_data.minimap_border);
}
