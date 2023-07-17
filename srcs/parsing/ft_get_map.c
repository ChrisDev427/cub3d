/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:20 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/16 00:17:25 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_count_lines(int fd)
{
	int		i;
	char	*s;

	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		free(s);
		if (!s)
			break ;
		i++;
	}
	return (i);
}

static void	ft_fill(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
		{
			dst[i] = '\0';
			break ;
		}
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static char	**ft_get(char **tab, int fd)
{
	int		i;
	char	*src;

	i = 0;
	while (1)
	{
		src = get_next_line(fd);
		if (!src)
		{
			tab[i] = 0;
			break ;
		}
		tab[i] = malloc(sizeof(char) * (ft_strlen(src) + 1));
		ft_fill(tab[i], src);
		i++;
		free(src);
	}
	return (tab);
}

char	**ft_get_map(t_game *game, char *file, char **tab)
{
	int	map_lines;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(game, "map: map file permission denied", NULL);
	map_lines = ft_count_lines(fd);
	tab = malloc(sizeof(char *) * (map_lines + 1));
	if (!tab)
		return (NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	ft_get(tab, fd);
	game->elem = malloc(sizeof(char *) * 7);
	if (!game->elem)
		return (NULL);
	game->elem_tmp = malloc(sizeof(char *) * 7);
	if (!game->elem_tmp)
		return (NULL);
	close(fd);
	return (tab);
}
