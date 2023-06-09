/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:44:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/09 09:11:58 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void    ft_init(t_game *game)
{
    game->data.elements = malloc(sizeof(char *) * 7);
    if (!game->data.elements)
        return ;
    game->win.mlx = mlx_init();
    game->win.win = mlx_new_window(game->win.mlx, WIDTH, HEIGHT, "cub3D");
	game->data.frame = 0;
    game->mov.camera[0] = 0;
    game->mov.camera[1] = 0;
    game->mov.moves[0] = 0;
    game->mov.moves[1] = 0;
    game->mov.moves[2] = 0;
    game->mov.moves[3] = 0;
    game->mov.deg = 0.0;
    game->mp_data.start_needle_x = 99;
	game->mp_data.start_needle_y = 99;
    ft_minimap_init(game);
}
