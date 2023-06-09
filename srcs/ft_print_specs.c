/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:01:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/09 13:09:14 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_print_specs(t_game *game)
{
    if (game->mov.moves[0] == 'u' || game->mov.moves[1] == 'l' || game->mov.moves[2] == 'r' || game->mov.moves[3] == 'd')
    {
        printf("pos_y = %f - player_y = %d - p_player_y = %d\n", game->mov.pos_y, game->mov.player_y, game->mov.p_player_y);        
        printf("pos_x = %f - player_x = %d - p_player_x = %d\n", game->mov.pos_x, game->mov.player_x, game->mov.p_player_x);
     
        printf("rad = %f\n", game->mov.rad);
        
    }
}