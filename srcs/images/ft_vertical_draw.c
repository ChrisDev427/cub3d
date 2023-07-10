/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:43:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/10 16:16:22 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_vertical_draw(t_game *game, int start, int end, int color)
{
    int y = 0;
	int y2 = 0;
    //printf("%d\n", color);
	float ratio = (float)(500.00 / (end - start));
	//float ratio_h = (float)(500.00 / (500 % 64));
	 //printf("ratio = %f\n", ratio);
	 //printf("end - start = %d\n", end - start);

    while (y < SCREEN_HEIGHT)
    {
        if (y < start)
            ft_my_mlx_pixel_put(&game->image.game_img , game->rc.ray_x, y, game->data.ce_color);
        if (y >= start && y <= end)
        {
        	//ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, start, color);
            //int pos = (start * game->image.north.line_length + game->rc.ray_x * (game->image.north.bits_per_pixel / 8));
            // game->image.north.addr = mlx_get_data_addr(game->image.north.img, &game->image.north.bits_per_pixel, &game->image.north.line_length, &game->image.north.endian);
            // *(unsigned int *)game->image.north.addr = color;
            // unsigned int *img_data = (unsigned int *)mlx_get_data_addr(game->image.north.img, &game->image.north.bits_per_pixel, &game->image.north.line_length, &game->image.north.endian);
			// unsigned int pixel = img_data[y * (game->image.north.line_length / 4) + game->rc.ray_x];
            // unsigned int red = (pixel & 0xFF0000) >> 16;
            // unsigned int green = (pixel & 0xFF00) >> 8;
            // unsigned int blue = pixel & 0xFF;
			int original_y = y2 * ratio;
			int original_x;
			if (game->rc.side == 0)
				original_x = game->pos_x + game->rc.perp_wall_dist * game->rc.ray_dir_x;
			else
				original_x = game->pos_y + game->rc.perp_wall_dist * game->rc.ray_dir_x;

			//int original_x  game->pos_y + game->rc.perp_wall_dist * game->rc.ray_dir_x;
			original_x -= floor(original_x);
			original_x *= 500;

			//dprintf(2, "y2 = %d\n", original_y);
			unsigned int *img_data = (unsigned int *)mlx_get_data_addr(game->image.tex[0].img, &game->image.tex[0].bits_per_pixel, &game->image.tex[0].line_length, &game->image.tex[0].endian);
			color = img_data[original_y * (game->image.tex[0].line_length / 4) + game->rc.map_x];
			ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, y, color);
			y2++;
            //mlx_pixel_put(game->win.mlx, game->win.win, game->rc.ray_x, start, *(unsigned int*)dst);
            start++;
        }
        if (y > end)
            ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, y, game->data.fl_color);
        y++;
    }
}

