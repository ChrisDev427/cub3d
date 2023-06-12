/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:01:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/12 14:07:50 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_print_specs(t_game *game)
{
    if (game->mov.moves[0] == 'u' || game->mov.moves[1] == 'l' || game->mov.moves[2] == 'r' || game->mov.moves[3] == 'd')
    {
        printf("pos_y = %f - player_y = %f\n", game->mov.pos_y, game->mov.player_y);
        printf("pos_x = %f - player_x = %f\n", game->mov.pos_x, game->mov.player_x);
        printf("rad = %f\n", game->mov.rad);

    }
}