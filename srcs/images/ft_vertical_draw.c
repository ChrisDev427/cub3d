/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:43:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/08 14:58:16 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_vertical_draw(t_game *game, int start, int end, int color)
{
    int y = 0;
    while (y < SCREEN_HEIGHT)
    {
        if (y < start)
            ft_my_mlx_pixel_put(&game->image.game_img , game->rc.ray_x, y, game->data.ce_color);
        if (y >= start && y <= end)
        {
            ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, start, color);
            start++;
        }
        if (y > end)
            ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, y, game->data.fl_color);
        y++;
    }
}

