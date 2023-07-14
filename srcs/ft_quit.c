/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:47:01 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 17:52:16 by chris            ###   ########.fr       */
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
