/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 17:09:35 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_color_assign(t_game *game)
{
	game->mp.mp_bg[0] = BG_COL_A;
	game->mp.mp_bg[1] = BG_COL_R;
	game->mp.mp_bg[2] = BG_COL_G;
	game->mp.mp_bg[3] = BG_COL_B;
	game->mp.mp_overmap[0] = OV_COL_A;
	game->mp.mp_overmap[1] = OV_COL_R;
	game->mp.mp_overmap[2] = OV_COL_G;
	game->mp.mp_overmap[3] = OV_COL_B;
	game->mp.mp_walls[0] = WL_COL_A;
	game->mp.mp_walls[1] = WL_COL_R;
	game->mp.mp_walls[2] = WL_COL_G;
	game->mp.mp_walls[3] = WL_COL_B;
	game->mp.mp_player[0] = PL_COL_A;
	game->mp.mp_player[1] = PL_COL_R;
	game->mp.mp_player[2] = PL_COL_G;
	game->mp.mp_player[3] = PL_COL_B;
}

static void	ft_color_init(t_game *game)
{
	game->mp.over_cl = ft_color_to_int(game->mp.mp_overmap);
	game->mp.walls_cl = ft_color_to_int(game->mp.mp_walls);
	game->mp.bg_cl = ft_color_to_int(game->mp.mp_bg);
	game->mp.pl_cl = ft_color_to_int(game->mp.mp_player);
}

void	ft_minimap_init(t_game *game)
{
	ft_color_assign(game);
	ft_color_init(game);
}
