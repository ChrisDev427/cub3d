/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 17:34:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->rc.dir_x;
	game->rc.dir_x = game->rc.dir_x * cos(game->rc.rot_speed) - game->rc.dir_y
		* sin(game->rc.rot_speed);
	game->rc.dir_y = old_dir_x * sin(game->rc.rot_speed) + game->rc.dir_y
		* cos(game->rc.rot_speed);
	old_plane_x = game->rc.plane_x;
	game->rc.plane_x = game->rc.plane_x * cos(game->rc.rot_speed)
		- game->rc.plane_y * sin(game->rc.rot_speed);
	game->rc.plane_y = old_plane_x * sin(game->rc.rot_speed) + game->rc.plane_y
		* cos(game->rc.rot_speed);
}

void	ft_rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->rc.dir_x;
	game->rc.dir_x = game->rc.dir_x * cos(-game->rc.rot_speed) - game->rc.dir_y
		* sin(-game->rc.rot_speed);
	game->rc.dir_y = old_dir_x * sin(-game->rc.rot_speed) + game->rc.dir_y
		* cos(-game->rc.rot_speed);
	old_plane_x = game->rc.plane_x;
	game->rc.plane_x = game->rc.plane_x * cos(-game->rc.rot_speed)
		- game->rc.plane_y * sin(-game->rc.rot_speed);
	game->rc.plane_y = old_plane_x * sin(-game->rc.rot_speed) + game->rc.plane_y
		* cos(-game->rc.rot_speed);
}

void	ft_camera(t_game *game)
{
	if (game->camera[0] == 'l')
	{
		game->rad += game->rc.rot_speed;
		if (game->rad > M_PI)
		game->rad = -M_PI;
		ft_rotate_right(game);
	}
	if (game->camera[1] == 'r')
	{
		game->rad -= game->rc.rot_speed;
		if (game->rad < -M_PI)
		game->rad = M_PI;
		ft_rotate_left(game);
	}
}
