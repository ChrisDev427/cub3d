/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_map_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:57 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/16 00:16:09 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_trim_map(t_game *game, int i)
{
	while (game->map[i] && strcmp(game->map[i], "") == 0)
		i++;
	if (!game->map[i])
		ft_error(game, "map : missing\n", NULL);
	game->map = &game->map[i];
}

static int	ft_token_match(char *s)
{
	if ((s[0] == 'N' && s[1] == 'O' && s[2] == ' ') || (s[0] == 'W' && s[1]
			== 'E' && s[2] == ' ') || (s[0] == 'S' && s[1] == 'O' && s[2]
			== ' ') || (s[0] == 'E' && s[1] == 'A' && s[2] == ' ') || (s[0]
			== 'F' && s[1] == ' ') || (s[0] == 'C' && s[1] == ' '))
		return (1);
	return (0);
}

static void	ft_ordering(t_game *game, char *tok)
{
	int		i;
	int		elem;
	int		j;

	i = 0;
	elem = 0;
	while (game->elem_tmp[i])
	{
		if (game->elem_tmp[i][0] == tok[elem])
		{
			j = 0;
			game->elem[elem] = ft_strdup(game->elem_tmp[i]);
			game->elem[elem] = &game->elem[elem][ft_str_chr(game->elem[elem],
					' ')];
			while (game->elem[elem][j] == ' ')
				j++;
			game->elem[elem] = &game->elem[elem][j];
			elem++;
			i = 0;
		}
		else
			i++;
	}
	if (elem != i)
		ft_error(game, "map: bad arguments\n", NULL);
}

void	ft_split_map_elem(t_game *game)
{
	int	i;

	i = -1;
	game->elem_nb = 0;
	while (game->map[++i])
	{
		if (ft_token_match(game->map[i]))
		{
			game->elem_tmp[game->elem_nb] = ft_strdup(game->map[i]);
			game->elem_nb++;
		}
		else if (ft_token_match(game->map[i]) == 0
			&& ft_strlen(game->map[i]) > 0)
			ft_error(game, "map: bad arguments\n", NULL);
		if (game->map[i][0] == ' ' || game->map[i][0] == '1')
			ft_error(game, "map: elements missing\n", NULL);
		if (game->elem_nb == 6)
			break ;
	}
	game->elem_tmp[game->elem_nb] = NULL;
	if (game->elem_nb != 6)
		ft_error(game, "map: invalid elements\n", NULL);
	ft_ordering(game, "NSWEFC");
	ft_trim_map(game, i + 1);
	free_str_tab(game->elem_tmp);
}
