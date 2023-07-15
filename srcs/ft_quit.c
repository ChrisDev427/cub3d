/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:47:01 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/15 12:20:55 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_quit(t_game *game)
{
	mlx_destroy_window(game->win.mlx, game->win.win);
	free_str_tab(game->mapcpy);
	exit(EXIT_SUCCESS);
	return (0);
}
