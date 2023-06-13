/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:01:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/13 15:05:06 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_print_specs(t_game *game)
{
    if (game->moves[0] == 'u' || game->moves[1] == 'l' || game->moves[2] == 'r'
        || game->moves[3] == 'd' || game->camera[0] == 'l' || game->camera[1] == 'r')
    {
        system("clear");
        printf("float_pos_y = %f - pixel_player_y = %d\n", game->player_y, game->pp_y);
        printf("float_pos_x = %f - pixel_player_x = %d\n", game->player_x, game->pp_x);
        printf("rad = %f\n\n", game->rad);
    }
}