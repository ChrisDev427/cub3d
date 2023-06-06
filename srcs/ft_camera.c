/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/05 10:58:06 by chmassa          ###   ########.fr       */
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
        game->mov.degrees -= 0.001;
    if (game->mov.camera[1] == 'r')
        game->mov.degrees += 0.001;
        
    // printf("position = %f\n", game->mov.degrees);
}