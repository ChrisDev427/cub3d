/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:31:36 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/11 09:14:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void ft_fill_tab(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (game->parse.map[y])
    {
        while (game->parse.map[y][x])
        {
            if (game->parse.map[y][x] == ' ')
                game->parse.maptmp[y][x] = '1';
            else
                game->parse.maptmp[y][x] = game->parse.map[y][x];
            x++;
        }
        while (x < game->parse.map_lines_len)
        {
            game->parse.maptmp[y][x] = '1';
            x++;
        }
        game->parse.maptmp[y][x] = '\0';
        y++;
        x = 0;
    }
    game->parse.maptmp[y] = 0;
}

int    ft_set_map_cpy(t_game *game)
{
    int i;

    i = 0;
    game->parse.map_nb_lines = ft_strtab_size(game->parse.map);
    game->parse.map_lines_len = ft_biggest_str_in_tab(game->parse.map);
    game->parse.maptmp = malloc(sizeof(char *) * (game->parse.map_nb_lines + 1));
    if (!game->parse.maptmp)
        return (-1);
    while (i < game->parse.map_nb_lines)
    {
        game->parse.maptmp[i] = malloc(sizeof(char) * (game->parse.map_lines_len + 1));
        if (!game->parse.maptmp)
            return (-1);
        i++;
    }
    ft_fill_tab(game);
    ft_enlarge_map(game);
    free_str_tab(game->parse.maptmp);
    
    return (0);
}
