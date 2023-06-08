/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_print_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:18:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/08 08:33:45 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_walls_floor(t_game *game, int y, int x, int color)
{
	int i = 0;
	int j = 0;
	int x_tmp;

	x_tmp = x;
	while (i <= MP_SIZE_LINES+1)
	{
		while (j <= MP_SIZE_LINES+1)
		{
			ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, color);
			j++;
			x++;
		}
		i++;
		y++;
		x = x_tmp;
		j = 0;
	}
}
// int** img;//each int is a pixel of the image
// img[x][y] = img[x][y] | (calc[x][y] & 0xFF000000);

void	ft_print_back_ground(t_game *game)
{
	int x;
	int y;
	
	y = 0;
	x = 0;
	while (y < MP_HEIGHT)
	{
		while (x < MP_WIDTH)
		{
			if (((y < 4) || (y > MP_HEIGHT -5) || (x < 4) || (x > MP_WIDTH -5))
				&& (game->mp_data.minimap_border[y][x] == '1'))
				ft_my_mlx_pixel_put(&game->image.minimap_img, x, y,
					game->mp_data.mp_border_color); // filling minimap border
			else if (game->mp_data.minimap_border[y][x] == '1')
				ft_my_mlx_pixel_put(&game->image.minimap_img, x, y,
					game->mp_data.mp_bg_color);    // filling minimap back ground
			x++;
		}
		y++;
		x = 0;
	}
}
