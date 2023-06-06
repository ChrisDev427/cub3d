/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/06 13:04:47 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_raycasting(t_game *game)
// {
// 	game->ray.x = 0;
// 	game->ray.posx = game->mov.pos_x;
// 	game->ray.posx = game->mov.pos_y;
// 	while (game->ray.x < game->win.x)
// 	{
// 	}
// }

int    ft_run(t_game *game)
{
    // ft_print_floor_ceiling(game);
    ft_camera(game);
	//ft_raycasting(game);

    return (0);
}