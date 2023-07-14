/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_map_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:57 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 17:30:05 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_trim_map(t_game *game, int i)
{
	while (strcmp(game->map[i], "") == 0)
		i++;
	game->map = &game->map[i];
	i = 0;
}

static int	ft_token_match(char *s)
{
	if ((s[0] == 'N' && s[1] == 'O') || (s[0] == 'W' && s[1] == 'E')
		|| (s[0] == 'S' && s[1] == 'O') || (s[0] == 'E' && s[1] == 'A')
		|| (s[0] == 'F' || s[0] == 'C'))
		return (1);
	return (0);
}

static void	ft_check_order(t_game *game)
{
	if (game->elem[0][0] != 'N' && game->elem[0][1] != 'O')
		ft_error(game, "map: invalid element order", NULL);
	if (game->elem[1][0] != 'S' && game->elem[1][1] != 'O')
		ft_error(game, "map: invalid element order", NULL);
	if (game->elem[2][0] != 'W' && game->elem[2][1] != 'E')
		ft_error(game, "map: invalid element order", NULL);
	if (game->elem[3][0] != 'E' && game->elem[3][1] != 'A')
		ft_error(game, "map: invalid element order", NULL);
	if (game->elem[4][0] != 'F')
		ft_error(game, "map: invalid element order", NULL);
	if (game->elem[5][0] != 'C')
		ft_error(game, "map: invalid element order", NULL);
}

void	ft_split_map_elem(t_game *game)
{
	int	i;
	int	elem_nb;

	i = 0;
	elem_nb = 0;
	game->elem = malloc(sizeof(char *) * 7);
	if (!game->elem)
		return ;
	while (game->map[i])
	{
		if (ft_token_match(game->map[i]))
		{
			game->elem[elem_nb] = ft_strdup(game->map[i]);
			elem_nb++;
		}
		if (elem_nb == 6)
			break ;
		i++;
	}
	game->elem[elem_nb] = NULL;
	if (elem_nb != 6)
		ft_error(game, "map: invalid elements\n", NULL);
	ft_check_order(game);
	ft_trim_map(game, i + 1);
	ft_set_map_cpy(game);
}
