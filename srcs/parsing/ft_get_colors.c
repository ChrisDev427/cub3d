/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:21:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/30 12:05:05 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_lexer(t_game *game, char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if ((s[i] == '-')
            || (s[i] == '+' && s[i-1] != ',' && s[i-1] != ' '))
            ft_error(game, "wrong color argument: ", s);
        if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ' && s[i]
            != 'F' && s[i] != 'C' && s[i] != '+')
            ft_error(game, "wrong color argument: ", s);
        i++;
    }
}
static void    ft_atoi_color(t_game *game, int *tab, char *s)
{
    int i;
    int byte;
    
    i = 0;
    byte = 0;
    ft_lexer(game, s);
    while (s[i])
    {
        if (s[i] >= '0' && s[i] <= '9')
        {  
            tab[byte] = ft_atoi(s+i);
            if (tab[byte] > 255)
                ft_error(game, "wrong color argument: ", s);
            byte++;
            while (ft_isdigit(s[i]))
                i++;
        }
        else
            i++;
    }
}

void    ft_get_colors(t_game *game)
{
    int i;

    i = 0;
    while (game->parse.elements[i])
    {
        if (game->parse.elements[i][0] == 'C')
            ft_atoi_color(game, game->parse.ceiling, game->parse.elements[i]);
        if (game->parse.elements[i][0] == 'F')
            ft_atoi_color(game, game->parse.floor, game->parse.elements[i]);
        i++;
    }
}