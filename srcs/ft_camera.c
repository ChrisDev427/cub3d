/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/08 15:28:29 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_camera(t_game *game)
{    
    if (game->mov.camera[0] == 'l')
    {
        game->mov.rad -= 0.05;
        if (game->mov.rad < -M_PI)
        game->mov.rad = M_PI;
    }
    if (game->mov.camera[1] == 'r')
    {
        game->mov.rad += 0.05;
        if (game->mov.rad > M_PI)
        game->mov.rad = -M_PI;
    }
    if (game->mov.str_deg)
        free(game->mov.str_deg);
    game->mov.str_deg = ft_itoa(game->mov.deg);
	
}