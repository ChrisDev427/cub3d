/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/05 16:13:24 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_moves(t_game *game)
{
    if (game->mov.moves[0] == 'u')
        game->mov.mp_pos_y -= 0.100;
    if (game->mov.moves[1] == 'l')
        game->mov.mp_pos_x -= 0.100;
    if (game->mov.moves[2] == 'r')
        game->mov.mp_pos_x += 0.100;
    if (game->mov.moves[3] == 'd')
        game->mov.mp_pos_y += 0.100;
    
}