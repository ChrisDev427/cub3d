/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/14 09:53:27 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static void	draw_axis(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	x = game->mp_data.start_needle_x;
// 	y = game->mp_data.start_needle_y;
// 	while (y < 160) // Hauteur de la fenêtre
// 	{
// 		// mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF); // Dessine un pixel blanc à la position (x, y)
// 		ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, 0xEA0000);
// 		y++;
// 	}
// }
// static void	ft_draw_axis(t_game *game)
// {
// 	game->mp_data.needle_length = 50; // Longueur de l'aiguille
	

// 	game->mp_data.end_needle_x = game->mp_data.start_needle_x + (int)(game->mp_data.needle_length * cos(game->mov.rad));
// 	game->mp_data.end_needle_y = game->mp_data.start_needle_y + (int)(game->mp_data.needle_length * sin(game->mov.rad));

// 	game->mp_data.dx = game->mp_data.end_needle_x - game->mp_data.start_needle_x;
// 	game->mp_data.dy = game->mp_data.end_needle_y - game->mp_data.start_needle_y;
// 	if (abs(game->mp_data.dx) > abs(game->mp_data.dy)) 
//     	game->mp_data.steps = abs(game->mp_data.dx);
// 	else
//     	game->mp_data.steps = abs(game->mp_data.dy);
// 	game->mp_data.x_increment = (float)game->mp_data.dx / (float)game->mp_data.steps;
// 	game->mp_data.y_increment = (float)game->mp_data.dy / (float)game->mp_data.steps;

// 	game->mov.pos_x = game->mp_data.start_needle_x;
// 	game->mov.pos_y = game->mp_data.start_needle_y;

// 	for (int i = 0; i <= game->mp_data.steps; i++)
// 	{
// 		game->mov.pos_x += game->mp_data.x_increment;
// 		game->mov.pos_y += game->mp_data.y_increment;
// 		ft_my_mlx_pixel_put(&game->image.minimap_img, game->mov.pos_x, game->mov.pos_y, 0xFFFFFF);
// 	}
// }
// void	rotate_axis(t_game *game)
// {
// 	int		needle_length = 50; // Longueur de l'aiguille

// 	game->mp_data.end_needle_x = game->mp_data.start_needle_x + (int)(needle_length * cos(game->mov.rad));
// 	game->mp_data.end_needle_y = game->mp_data.start_needle_y + (int)(needle_length * sin(game->mov.rad));

// 	// mlx_clear_window(game->win.mlx, game->win.win); // Efface la fenêtre
// 	ft_draw_axis(game); // Dessine l'axe fixe
// 	// ft_my_mlx_pixel_put(&game->image.minimap_img, game->mp_data.start_needle_x, game->mp_data.start_needle_y, 0xEA0000);
// 	// ft_my_mlx_pixel_put(&game->image.minimap_img, game->mp_data.end_needle_x, game->mp_data.end_needle_y, 0xEA0000);

// 	// mlx_pixel_put(game->win.mlx, game->win.win, game->mp_data.center_needle_x, game->mp_data.center_needle_y, 0xFF0000); // Dessine le point de rotation en rouge
// 	// mlx_pixel_put(game->win.mlx, game->win.win, end_x, end_y, 0x00FF00); // Dessine l'extrémité de l'aiguille en vert
// }
// static void	ft_draw_player(t_game *game, int y, int x, int color)
// {
// 	int i = 0;
// 	int j = 0;
// 	int x_tmp;

// 	x_tmp = x;
// 	while (i < 20)
// 	{
// 		while (j < 20)
// 		{
// 			ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, color);
// 			j++;
// 			x++;
// 		}
// 		i++;
// 		y++;
// 		x = x_tmp;
// 		j = 0;
// 	}
// }


static void	ft_print_minimap(t_game *game)
{
	int	i = 0;
	int	j = 0;
	int	y = game->pp_y - (MP_HEIGHT /2);
	int	x = game->pp_x - (MP_WIDTH /2);

	while (i < MP_HEIGHT)
	{
		while (j < MP_WIDTH)
		{
			if (game->mapcpy[y /20][x /20] == '0')
				ft_my_mlx_pixel_put(&game->image.minimap_img, j, i, game->mp_data.mp_floor_color);
			if (game->mapcpy[y /20][x /20] == '1')
				ft_my_mlx_pixel_put(&game->image.minimap_img, j, i, game->mp_data.mp_walls_color);
			x++;
			j++;
		}
		i++;
		y++;
		x = game->pp_x - (MP_WIDTH /2);
		j = 0;
	}
}
void	ft_mini_map(t_game *game)
{
	ft_print_back_ground(game);
	ft_print_minimap(game);
	// rotate_axis(game);
	ft_draw_player(game, (MP_HEIGHT / 2), (MP_WIDTH / 2), game->mp_data.mp_player_color);
}
