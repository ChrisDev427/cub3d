/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_map_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:57 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/12 21:04:28 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void ft_trim_map(t_game *game, int i)
{
    while (strcmp(game->parse.map[i], "") == 0)
        i++;
    game->parse.map = &game->parse.map[i];
    i = 0;
    while (game->parse.map[i] && strcmp(game->parse.map[i], "") != 0)
        i++;
    game->parse.map[i] = NULL;
}

static int  ft_token_match(char *s)
{
    if ((s[0] == 'N' && s[1] == 'O') || (s[0] == 'W' && s[1] == 'E')
        || (s[0] == 'S' && s[1] == 'O') || (s[0] == 'E' && s[1] == 'A')
            || (s[0] == 'F' || s[0] == 'C'))
            return (1);

    return (0);
}

void	ft_split_map_elem(t_game *game)
{
    int     i;
	int		elem_nb;

    i = 0;
    elem_nb = 0;
    while (game->parse.map[i])
    {
        if (ft_token_match(game->parse.map[i]))
        {
            game->data.elements[elem_nb] = ft_strdup(game->parse.map[i]);
            elem_nb++;
        }
        if (elem_nb == 6)
            break ;
        i++;
    }
    game->data.elements[elem_nb] = NULL;
    if (elem_nb != 6)
        ft_error(game, "map: invalid elements\n", NULL);
    ft_trim_map(game, i + 1);
	ft_set_map_cpy(game);
}
