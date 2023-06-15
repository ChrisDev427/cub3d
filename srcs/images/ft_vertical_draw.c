/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:43:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 14:40:37 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_vertical_draw(t_game *game, int start, int end, int color)
{
    while (start < end)
    {
        ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, start, color);
        start++;
    }
}