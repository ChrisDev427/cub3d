/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:02:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 16:52:24 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(t_game *game, char *s1, char *s2)
{
	(void)game;
	ft_putstr_fd("Error: ", 2);
	write(2, "\'", 1);
	ft_putstr_fd(s1, 2);
	write(2, "\'", 1);

	if (s2)
	{
		ft_putstr_fd(s2, 2);
		ft_putstr_fd("\n", 2);
	}
	// free_str_tab(game->parse.map);
	exit (EXIT_FAILURE);
}
