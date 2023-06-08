/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_title.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:48:43 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/08 11:39:34 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_title(t_game *game)
{
    int x;
	int y;
	y = 0;
	x = 0;
	while (y < TITLE_HEIGHT)
	{
		while (x < TITLE_WIDTH)
		{
	        ft_my_mlx_pixel_put(&game->image.title_img, x, y, 0x181818); // filling title back ground
			x++;
		}
		y++;
		x = 0;
	}
    mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.title_img.img, 0, 1000);
	mlx_string_put(game->win.mlx, game->win.win, 20, 1005, 0x00CF10, "chmassa/axfernan cub3D_42_project june 2023");
	mlx_string_put(game->win.mlx, game->win.win, 940, 1005, 0xDC0000, "[dir.");
	mlx_string_put(game->win.mlx, game->win.win, 1000, 1005, 0xDC0000, game->mov.str_deg);
	mlx_string_put(game->win.mlx, game->win.win, 1040, 1005, 0xDC0000, "deg.]");
}