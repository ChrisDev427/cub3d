/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/06 19:07:21 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_camera(t_game *game)
{
    if (game->mov.degrees > 359)
        game->mov.degrees = 0;
    if (game->mov.degrees < 0)
        game->mov.degrees = 359;
    
    if (game->mov.camera[0] == 'l')
        game->mov.degrees -= 1;
    if (game->mov.camera[1] == 'r')
        game->mov.degrees += 1;
    if (game->mov.str_deg)
        free(game->mov.str_deg);
    game->mov.str_deg = ft_itoa(game->mov.degrees);
	
}