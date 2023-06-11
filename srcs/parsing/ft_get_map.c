/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:20 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/11 09:18:54 by chris            ###   ########.fr       */
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
    int i;

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
	dst[i]= '\0';
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

char    **ft_get_map(char *file, char **tab)
{
	int		map_lines;
    int     fd;
    
	fd = open(file, O_RDONLY);
	map_lines = ft_count_lines(fd);
	tab = malloc(sizeof(char *) * (map_lines + 1));
	fd = open(file, O_RDONLY);
	ft_get(tab, fd);
    return (tab);
}