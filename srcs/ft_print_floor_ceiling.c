/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floor_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:11:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/05 14:10:13 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_print_floor_ceiling(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
            if (y < HEIGHT / 2)
                ft_my_mlx_pixel_put(&game->image.game_img , x, y, game->data.ce_color);
            else
                ft_my_mlx_pixel_put(&game->image.game_img, x, y, game->data.fl_color);
            x++;
        }
        y++;
        x = 0;
    }
    mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.game_img.img, 0, 0);
}