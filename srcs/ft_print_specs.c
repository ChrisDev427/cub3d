/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:01:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/12 09:30:17 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_print_specs(t_game *game)
{
    if (game->mov.moves[0] == 'u' || game->mov.moves[1] == 'l' || game->mov.moves[2] == 'r'
        || game->mov.moves[3] == 'd' || game->mov.camera[0] == 'l' || game->mov.camera[1] == 'r')
    {
        system("clear");
        printf("pos_y = %f - player_y = %d - p_player_y = %d\n", game->mov.pos_y, game->mov.player_y, game->mov.p_player_y);        
        printf("pos_x = %f - player_x = %d - p_player_x = %d\n", game->mov.pos_x, game->mov.player_x, game->mov.p_player_x);
        printf("rad = %f\n\n", game->mov.rad);
    }
}