/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:21:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/15 20:43:46 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_lexer(t_game *game, char *s)
{
	int	i;
	int	nb_comma;

	i = 0;
	nb_comma = 0;
	if (ft_strlen(s) > 11)
		ft_error(game, "wrong color argument\n", NULL);
	while (s[i])
	{
		if ((s[i] == '+' && s[i - 1] != ',' && s[i - 1] != ' '))
			ft_error(game, "wrong color argument\n", NULL);
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ' && s[i]
			!= 'F' && s[i] != 'C' && s[i] != '+')
			ft_error(game, "wrong color argument\n", NULL);
		if (s[i] == ',')
			nb_comma++;
		i++;
	}
	if (nb_comma != 2)
		ft_error(game, "wrong color argument\n", NULL);
}

static void	ft_atoi_color(t_game *game, int *tab, char *s)
{
	int	i;
	int	byte;

	i = 0;
	byte = 1;
	ft_lexer(game, s);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			tab[byte] = ft_atoi(s + i);
			if (tab[byte] < 0 || tab[byte] > 255)
				ft_error(game, "wrong color argument\n", NULL);
			byte++;
			while (ft_isdigit(s[i]))
				i++;
		}
		else
			i++;
	}
	if (byte < 4)
		ft_error(game, "color argument is missing\n", NULL);
}

int	ft_color_to_int(int *tab_color)
{
	return (tab_color[3] + tab_color[2] * 256 + tab_color[1] * 256 * 256
		+ tab_color[0] * 256 * 256 * 256);
}

void	ft_get_colors(t_game *game)
{
	game->data.ceiling[0] = 0;
	game->data.floor[0] = 0;
	ft_atoi_color(game, game->data.ceiling, game->elem[5]);
	ft_atoi_color(game, game->data.floor, game->elem[4]);
	game->data.ce_color = ft_color_to_int(game->data.ceiling);
	game->data.fl_color = ft_color_to_int(game->data.floor);
}
