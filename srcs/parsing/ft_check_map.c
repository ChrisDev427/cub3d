/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:09:45 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/08 22:01:52 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	walls_is_surrounding(char **tab)
{
	int	y;
	int	x;

	y = 0;
	while (tab[y])
	{
		x = 0;
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
	position_founded = 0;
	s = "10NWSE ";
	while (tab[y])
	{
        x = 0;
        while (tab[y][x])
        {
			if (tab[y][x] == 'N' || tab[y][x] == 'S'
				|| tab[y][x] == 'E' || tab[y][x] == 'W')
					position_founded++;
			if (ft_found_char(s, tab[y][x]) == 0)
                return (1);
            x++;
        }
		y++;
	}
	if (position_founded != 1)
		return (1);
	return (0);
}

void	ft_check_map(t_game *game)
{
	if (check_element(game->map) == 1)
		ft_error(game, "map must contain: 0 - 1 and one of the position/direction -> N - W - S - E\n", NULL);
	if (walls_is_surrounding(game->map) == 1)
		ft_error(game, "map must be sourrounded by walls\n", NULL);
}
