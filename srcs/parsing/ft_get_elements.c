/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:57 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/26 12:04:54 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char **ft_init_elem(char **tab)
{
    tab[0] = "NO ./";
    tab[1] = "SO ./";
    tab[2] = "WE ./";
    tab[3] = "EA ./";
    tab[4] = "F ./";
    tab[5] = "C ./";
    tab[6] = NULL;
    return (tab);
}

void	ft_get_elements(t_game *game)
{
	int		nb_elements;
    int     i;
    char    *elem[7];
    
    *elem = *ft_init_elem(elem);

    i = 0;
    nb_elements = 0;
    while (game->parse.map[i])
    {
        // if (ft_strnstr(game->parse.map[i], ""))

    }

	

}