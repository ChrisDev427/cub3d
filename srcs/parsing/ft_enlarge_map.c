/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enlarge_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:08:32 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/03 15:26:20 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void ft_fill_first_ten_lines(t_game *game)
{
    game->data.y = 0;
    game->data.x = 0;
    while (game->data.y < 10)
    {
        while (game->data.x < game->map_lines_len)
        {
            game->mapcpy[game->data.y][game->data.x] = '|';
            game->data.x++;
        }
        if (game->data.y < 10)
            game->mapcpy[game->data.y][game->data.x] = '\0';
        game->data.y++;
        game->data.x = 0;
    }
}

static void ft_fill_last_ten_lines(t_game *game, int x, int y)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < 10)
    {
        while (j < game->map_lines_len)
        {
            game->mapcpy[y][x] = '|';
            j++;
            x++;
        }
        game->mapcpy[y][x] = '\0';
        i++;
        y++;
        j = 0;
        x = 0;
    }
    game->mapcpy[y] = 0;
}

static void ft_fill_tab(t_game *game)
{
    int y;
    int x;
    int i;
    int j;

    ft_fill_first_ten_lines(game);
    y = game->data.y;
    x = game->data.x;
    i = 0;
    j = 0;
    while (game->maptmp[i])
    {
        while (x < 10)
            game->mapcpy[y][x++] = '|';
        while (game->maptmp[i][j])
            game->mapcpy[y][x++] = game->maptmp[i][j++];
        while (x < game->map_lines_len)
            game->mapcpy[y][x++] = '|';
        game->mapcpy[y][x] = '\0';
        y++;
        i++;
        x = 0;
        j = 0;
    }
    ft_fill_last_ten_lines(game, x, y);
}

static int ft_alloc(t_game *game)
{
    int     i;

    i = 0;
    game->map_nb_lines = ft_strtab_size(game->maptmp) +20;
    game->map_lines_len = ft_biggest_str_in_tab(game->maptmp) +20;
    game->mapcpy = malloc(sizeof(char *) * (game->map_nb_lines + 1));
    if (!game->mapcpy)
        return (-1);
    while (i < game->map_nb_lines)
    {
        game->mapcpy[i] = malloc(sizeof(char) * (game->map_lines_len + 1));
        if (!game->mapcpy)
            return (-1);
        i++;
    }
    return (0);
}

void    ft_enlarge_map(t_game *game)
{
    ft_alloc(game);
    ft_fill_tab(game);
    
}
