/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:09:45 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/30 19:39:40 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

// static void	check_size(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	len;

// 	x = ft_strlen(game->parse.map[0]);
// 	y = 0;
// 	while (game->parse.map[y])
// 	{
// 		len = ft_strlen(game->parse.map[y]);
// 		if (len != x)
// 			ft_error(game, "map shape error !");
// 		y++;
// 	}
// 	if (x > 60 || y > 33)
// 		ft_error(game, "map size is too big");
// }



static int	walls_is_surrounding(char **tab)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		if (tab[y][0] != '1' && tab[y][0] != ' ')
				return (1);
        while (tab[y][x])
		{
			if (tab[y][x] == '0')
			{
				if (tab[y +1] == NULL || tab[y][x +1] == ' '
					|| tab[y][x +1] == '\0' || tab[y][x -1] == ' '
						|| tab[y +1][x] == ' ' || tab[y -1][x] == ' ')
						return (1);
			}
            x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

static int	check_element(char **tab)
{
	int		y;
	int		x;
	int		position_founded;
	char	*s;

	y = 0;
	x = 0;
	position_founded = 0;
	s = "10NWSE ";
	while (tab[y])
	{
        while (tab[y][x])
        {
			if (tab[y][x] == 'N' || tab[y][x] == 'S'
				|| tab[y][x] == 'E' || tab[y][x] == 'W')
					position_founded++;
			if (ft_found_char(s, tab[y][x]) == 0)
                return (1);
            x++;
        }
        x = 0;
		y++;
	}
	if (position_founded != 1)
		return (1);
	return (0);
}

void	ft_check_map(t_game *game)
{
// 	check_size(game);
	if (check_element(game->parse.map) == 1)
		ft_error(game, "map must contain: 0 - 1 and one of the position/direction -> N - W - S - E\n", NULL);
	if (walls_is_surrounding(game->parse.map) == 1)
		ft_error(game, "map must be sourrounded by walls\n", NULL);

// 	if (check_element(game, 'C') == 0)
// 		ft_error(game, "collectible is missing !\n");
// 	if (check_element(game, 'P') == 0 || check_element(game, 'P') > 1)
// 		ft_error(game, "start position is missing or more than 1 !\n");
}
