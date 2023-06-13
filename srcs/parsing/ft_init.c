/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:44:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/13 14:05:43 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void    ft_init(t_game *game)
{
    game->data.elements = malloc(sizeof(char *) * 7);
    if (!game->data.elements)
        return ;
    game->win.mlx = mlx_init();
    game->win.win = mlx_new_window(game->win.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	game->data.frame = 0;
    game->camera[0] = 0;
    game->camera[1] = 0;
    game->moves[0] = 0;
    game->moves[1] = 0;
    game->moves[2] = 0;
    game->moves[3] = 0;
    game->deg = 0.0;
    game->mp_data.start_needle_x = 99;
	game->mp_data.start_needle_y = 99;
    ft_minimap_init(game);
}
