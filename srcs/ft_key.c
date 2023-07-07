/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:01:52 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/07 09:56:06 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	ft_keyrelease(int key, t_game *game)
{
	if (key == 13)
		game->moves[0] = '0';
	if (key == 0)
		game->moves[1] = '0';
	if (key == 2)
		game->moves[2] = '0';
	if (key == 1)
		game->moves[3] = '0';
	if (key == 123)
		game->camera[0] = '0';
	if (key == 124)
		game->camera[1] = '0';
	if (key == 126)
		game->slow = '0';
	if (key == 125)
		game->fast = '0';

	return (0);
}

int	ft_keypress(int key, t_game *game)
{
	// if (key == 36)
	// 	game->start_game = 1;
	// printf("key -> %d\n", key);
	if (key == 53)
		ft_quit(game);
	if (key == 13)
		game->moves[0] = 'u';
	if (key == 0)
		game->moves[1] = 'l';
	if (key == 2)
		game->moves[2] = 'r';
	if (key == 1)
		game->moves[3] = 'd';
	if (key == 123)
		game->camera[0] = 'l';
	if (key == 124)
		game->camera[1] = 'r';
	if (key == 126)
		game->slow = 's';
	if (key == 125)
		game->fast = 'f';
	return (0);
}
