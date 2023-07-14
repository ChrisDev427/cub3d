/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:21:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 17:50:39 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_lexer(t_game *game, char *s)
{
	int	i;
	int	nb_comma;

	i = 0;
	nb_comma = 0;
	while (s[i])
	{
		if ((s[i] == '-')
			|| (s[i] == '+' && s[i - 1] != ',' && s[i - 1] != ' '))
			ft_error(game, "wrong color argument: ", s);
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ' && s[i]
			!= 'F' && s[i] != 'C' && s[i] != '+')
			ft_error(game, "wrong color argument: ", s);
		if (s[i] == ',')
			nb_comma++;
		i++;
	}
	if (nb_comma != 2)
		ft_error(game, "wrong color argument: ", s);
}

static void	ft_atoi_color(t_game *game, int *tab, char *s)
{
	int	i;
	int	byte;

	i = 0;
	tab[0] = 0;
	byte = 1;
	ft_lexer(game, s);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			tab[byte] = ft_atoi(s + i);
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

int	ft_color_to_int(int *tab_color)
{
	return (tab_color[3] + tab_color[2] * 256 + tab_color[1] * 256 * 256
		+ tab_color[0] * 256 * 256 * 256);
}

void	ft_get_colors(t_game *game)
{
	int	i;

	i = 0;
	while (game->elem[i])
	{
		if (game->elem[i][0] == 'C')
			ft_atoi_color(game, game->data.ceiling, game->elem[i]);
		if (game->elem[i][0] == 'F')
			ft_atoi_color(game, game->data.floor, game->elem[i]);
		i++;
	}
	game->data.ce_color = ft_color_to_int(game->data.ceiling);
	game->data.fl_color = ft_color_to_int(game->data.floor);
}
