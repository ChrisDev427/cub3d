/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/07 16:46:07 by chmassa          ###   ########.fr       */
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
	game->mp_data.mini_map_border[0] = BR_COL_A;
	game->mp_data.mini_map_border[1] = BR_COL_R;
	game->mp_data.mini_map_border[2] = BR_COL_G;
	game->mp_data.mini_map_border[3] = BR_COL_B;
}

static void	ft_color_init(t_game *game)
{
	game->mp_data.mp_floor_color = ft_color_to_int(game->mp_data.mini_map_floor);
	game->mp_data.mp_walls_color = ft_color_to_int(game->mp_data.mini_map_walls);
	game->mp_data.mp_bg_color = ft_color_to_int(game->mp_data.mini_map_bg);
	game->mp_data.mp_player_color = ft_color_to_int(game->mp_data.mini_map_player);
	game->mp_data.mp_border_color = ft_color_to_int(game->mp_data.mini_map_border);
}
void	ft_init_variables(t_game *game, int *x, int *y)
{
	game->mp_data.y_tmp = *y;
	game->mp_data.x_tmp = *x;
	*y -= 10;
	*x -= 10;
	game->mp_data.y_mp = 5;
	game->mp_data.x_mp = 5;
	game->mp_data.player_radius_border[0] = "001111100";
	game->mp_data.player_radius_border[1] = "011111110";
	game->mp_data.player_radius_border[2] = "111111111";
	game->mp_data.player_radius_border[3] = "111111111";
	game->mp_data.player_radius_border[4] = "111111111";
	game->mp_data.player_radius_border[5] = "111111111";
	game->mp_data.player_radius_border[6] = "111111111";
	game->mp_data.player_radius_border[7] = "011111110";
	game->mp_data.player_radius_border[8] = "001111100";
}

void	ft_minimap_init(t_game *game)
{
	int	fd;
	ft_color_assign(game);
	ft_color_init(game);
	fd = open("mp_map_border.txt", O_RDONLY);
	game->mp_data.minimap_border = ft_get_map("mp_map_border.txt", game->mp_data.minimap_border);
}
