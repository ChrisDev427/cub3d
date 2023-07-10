/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:43:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/10 17:16:34 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void    ft_vertical_draw(t_game *game, int start, int end, int color)
// {
//     int y = 0;
//     while (y < SCREEN_HEIGHT)
//     {
//         if (y < start)
//             ft_my_mlx_pixel_put(&game->image.game_img , game->rc.ray_x, y, game->data.ce_color);
//         if (y >= start && y <= end)
//         {

//             ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, start, color);
//             start++;
//         }
//         if (y > end)
//             ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, y, game->data.fl_color);
//         y++;
//     }
// }

void    ft_vertical_draw(t_game *game, int start, int end, int color)
{
    int y = 0;
    int yb = 0;
    unsigned int *img_data = (unsigned int*)game->image.tex[0].addr;
    while (y < SCREEN_HEIGHT)
    {
        if (y < start)
            ft_my_mlx_pixel_put(&game->image.game_img , game->rc.ray_x, y, game->data.ce_color);
        if (y >= start && y <= end)
        {
            int x = game->rc.ray_x * game->rc.ratio + (game->rc.map_x * game->rc.map_y) ;
            int y2 = yb * game->rc.ratio;
            color = img_data[y2 * game->image.tex[0].line_length /4 + x];
            ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, start, color);
            start++;
            yb++;
        }
        if (y > end)
            ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, y, game->data.fl_color);
        y++;
        
    }
}

    