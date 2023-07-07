/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_print_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:18:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/18 10:24:04 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_player(t_game *game, int y, int x, int color)
{
	int i;
	int j;
	int x_tmp;

	x_tmp = x;
	i = 0;
	while (i < 20)
	{
		j = 0;
		x = x_tmp;
		while (j < 20)
		{
			ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, color);
			j++;
			x++;
		}
		i++;
		y++;
	}
}

void	ft_print_back_ground(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < MP_HEIGHT)
	{
		j = 0;
		while (j < MP_WIDTH)
		{
			ft_my_mlx_pixel_put(&game->image.minimap_img, j, i, game->mp_data.mp_bg_color);    // filling minimap back ground
			j++;
		}
		i++;
	}
}
