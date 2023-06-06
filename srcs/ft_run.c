/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/06 19:06:58 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    ft_run(t_game *game)
{
    if (game->data.frame == 200)
        game->data.frame = 0;
    game->data.frame++;

    // ft_print_floor_ceiling(game);
    // if (game->data.frame % 6 == 1)
        ft_camera(game);
    ft_mini_map(game);
    if (game->data.frame % 6 == 1)
        ft_moves(game);
    // printf("%f\n", game->mov.degrees);
    // printf("%d\n", game->data.frame);
	ft_title(game);
   
    return (0);
}