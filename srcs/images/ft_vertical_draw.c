/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:43:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/15 07:38:57 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_draw_tex(t_game *game)
{
	int	color;
	int	x;

	x = game->rc.wallx * game->rc.tex_size_w;
	color = game->image.img_data[game->rc.tex][(int)nearbyint(game->rc.tex_y)
		* game->image.tex[game->rc.tex].line_length / 4 + x];
	ft_my_pixel_put(&game->image.game_img, game->rc.ray_x,
		game->rc.y_draw, color);
	game->rc.tex_y += game->rc.ratio;
}

void	ft_vertical_draw(t_game *game)
{
	game->rc.y_draw = 0;
	if (game->rc.draw_start < 0)
		game->rc.tex_y = abs(game->rc.draw_start) * game->rc.ratio;
	else
		game->rc.tex_y = 0;
	while (game->rc.y_draw < SCREEN_HEIGHT)
	{
		if (game->rc.y_draw < game->rc.draw_start)
			ft_my_pixel_put(&game->image.game_img, game->rc.ray_x,
				game->rc.y_draw, game->data.ce_color /*| 192 << 24*/);
		if (game->rc.y_draw >= game->rc.draw_start && game->rc.y_draw
			< game->rc.draw_end)
			ft_draw_tex(game);
		if (game->rc.y_draw >= game->rc.draw_end)
			ft_my_pixel_put(&game->image.game_img, game->rc.ray_x,
				game->rc.y_draw, game->data.fl_color /*| 192 << 24*/);
		game->rc.y_draw++;
	}
}
