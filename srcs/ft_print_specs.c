/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:01:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 11:16:05 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_print_specs(t_game *game)
{
    if (game->moves[0] == 'u' || game->moves[1] == 'l' || game->moves[2] == 'r'
        || game->moves[3] == 'd' || game->camera[0] == 'l' || game->camera[1] == 'r')
    {
        system("clear");
        printf("float_pos_x = %f - ipos_x = %d - pixel_player_x = %d\n", game->fpos_x, game->ipos_x, game->ppos_x);
        printf("float_pos_y = %f - ipos_y = %d - pixel_player_y = %d\n", game->fpos_y, game->ipos_y, game->ppos_y);
        printf("rad = %f\n", game->rad);
        printf("dir_x = %f\n", game->rc.dir_x);
        printf("dir_y = %f\n", game->rc.dir_y);
        puts("");

    }
}