/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:21:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/31 17:19:28 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int ft_lexer(t_game *game, char *s)
{
	int i;
	int nb_comma;

	i = 0;
	nb_comma = 0;
	while(s[i])
	{
		if ((s[i] == '-')
			|| (s[i] == '+' && s[i-1] != ',' && s[i-1] != ' '))
			ft_error(game, "wrong color argument: ", s);
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ' && s[i]
			!= 'F' && s[i] != 'C' && s[i] != '+')
			ft_error(game, "wrong color argument: ", s);
		if (s[i] == ',')
			nb_comma++;
		i++;
	}
	if (nb_comma == 2)
		return (2);
	if (nb_comma == 3)
		return (3);
	return (0);
}
static void    ft_atoi_color(t_game *game, int *tab, char *s)
{
	int i;
	int byte;
	
	i = 0;
	byte = 0;
	if (ft_lexer(game, s) == 2)
		tab[3] = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{  
			tab[byte] = ft_atoi(s+i);
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

static void ft_color_to_int(int *color, int *tab_color)
{
//    *color = tab_color[3] + tab_color[2] * 256 + tab_color[1] * 256 * 256
//           + tab_color[0] * 256 * 256 * 256;
	*color = tab_color[3] | tab_color[2] << 8 | tab_color[1] << 16 | tab_color[0] << 24; //same as above, but with bitshift
}

void    ft_get_colors(t_game *game)
{
	int i;

	i = 0;
	while (game->data.elements[i])
	{
		if (game->data.elements[i][0] == 'C')
			ft_atoi_color(game, game->data.ceiling, game->data.elements[i]);
		if (game->data.elements[i][0] == 'F')
			ft_atoi_color(game, game->data.floor, game->data.elements[i]);
		i++;
	}
	ft_color_to_int(&game->data.ce_color, game->data.ceiling);
	ft_color_to_int(&game->data.fl_color, game->data.floor);
	
	
}
