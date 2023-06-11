/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/11 09:24:34 by chris            ###   ########.fr       */
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
}