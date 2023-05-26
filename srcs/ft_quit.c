/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:47:01 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/26 11:20:32 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_quit(t_game *game)
{
	game = NULL;
	// mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	// free_str_tab(game->parse.map);
	exit(EXIT_SUCCESS);
	return (0);
}
