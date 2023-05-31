/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:44:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/31 17:24:37 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    ft_init(t_game *game)
{
    game->data.elements = malloc(sizeof(char *) * 7);
    if (!game->data.elements)
        return ;
    game->win.size_x = 1920;
    game->win.size_y = 1080;
    game->win.mlx = mlx_init();
    game->win.win = mlx_new_window(game->win.mlx, game->win.size_x,
    game->win.size_y, "Chris&Axel_cub3D");
	
    game->mov.camera[0] = 0;
    game->mov.camera[1] = 0;
    game->mov.moves[0] = 0;
    game->mov.moves[1] = 0;
    game->mov.moves[2] = 0;
    game->mov.moves[3] = 0;
    game->mov.degrees = 0.0;


}
