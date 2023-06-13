/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/13 14:05:17 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_camera(t_game *game)
{
    if (game->camera[0] == 'l')
    {
        game->rad -= 0.05;
        if (game->rad < -M_PI)
        game->rad = M_PI;
    }
    if (game->camera[1] == 'r')
    {
        game->rad += 0.05;
        if (game->rad > M_PI)
        game->rad = -M_PI;
    }
}