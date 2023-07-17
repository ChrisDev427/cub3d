/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:31:36 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/16 00:08:05 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_fill_tab(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == ' ')
				game->maptmp[y][x] = '|';
			else
				game->maptmp[y][x] = game->map[y][x];
			x++;
		}
		while (x < game->map_lines_len)
		{
			game->maptmp[y][x] = '|';
			x++;
		}
		game->maptmp[y][x] = '\0';
		y++;
		x = 0;
	}
	game->maptmp[y] = 0;
}

static void	ft_check_valid_path(t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(game->elem[i], O_RDONLY);
		if (fd < 0)
			ft_error(game, "texture does not exist\n", NULL);
		close(fd);
		i++;
	}
}

int	ft_set_map_cpy(t_game *game)
{
	int	i;

	i = 0;
	ft_check_valid_path(game);
	game->map_nb_lines = ft_strtab_size(game->map);
	game->map_lines_len = ft_biggest_str_in_tab(game->map);
	game->maptmp = malloc(sizeof(char *) * (game->map_nb_lines + 1));
	if (!game->maptmp)
		return (-1);
	while (i < game->map_nb_lines)
	{
		game->maptmp[i] = malloc(sizeof(char) * (game->map_lines_len + 1));
		if (!game->maptmp)
			return (-1);
		i++;
	}
	ft_fill_tab(game);
	ft_enlarge_map(game);
	free_str_tab(game->maptmp);
	return (0);
}
