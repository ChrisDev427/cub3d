/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:03:53 by chris             #+#    #+#             */
/*   Updated: 2023/07/06 15:13:28 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_speed(t_game *game)
{
    if (game->slow == 's')
    {
        game->rc.move_speed =  0.01;
        game->rc.rot_speed =  0.001;
        game->state = "slow";
    }
    else if (game->fast == 'f')
    {
        game->rc.move_speed =  0.3;
        game->rc.rot_speed =  0.1;
        game->state = "fast";
    }
    else
    {
        game->rc.rot_speed = ROT_SPEED;
        game->rc.move_speed =  MOVE_SPEED;
        game->state = "normal";
    }
}
