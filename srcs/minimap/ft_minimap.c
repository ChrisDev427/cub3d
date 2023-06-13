/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/13 15:32:44 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_axis(t_game *game, double pos)
{
	int		needle_length = 30; // Longueur de l'aiguille

	game->mp_data.end_needle_x = game->pp_x - (int)(needle_length * cos(game->rad + pos));
	game->mp_data.end_needle_y = game->pp_y - (int)(needle_length * sin(game->rad + pos));

	int	dx = game->mp_data.end_needle_x - game->pp_x;
	int	dy = game->mp_data.end_needle_y - game->pp_y;
	int	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float	x_increment = (float)dx / (float)steps;
	float	y_increment = (float)dy / (float)steps;

	float pos_x = (MP_WIDTH / 2 + 10);
	float pos_y = (MP_HEIGHT / 2 + 10);

	for (int i = 0; i <= steps; i++)
	{
		pos_x += x_increment;
		pos_y += y_increment;
		ft_my_mlx_pixel_put(&game->image.minimap_img, pos_x, pos_y, 0x643575);
	}
}
static void	ft_print_minimap(t_game *game)
{
	int x = 0;
	int y = 0;
	int i;
	int j;
	j = game->pp_y - (MP_HEIGHT / 2);

	while (y < MP_HEIGHT)
	{
		i = game->pp_x - (MP_WIDTH / 2);
		x = 0;
		while (x < MP_WIDTH)
		{
            if (game->mapcpy[j / 20][i / 20] == '0')
                ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, game->mp_data.mp_floor_color);
            else if (game->mapcpy[j / 20][i / 20] == '1')
                ft_my_mlx_pixel_put(&game->image.minimap_img, x, y, game->mp_data.mp_walls_color);
            x++;
            i++;
        }
        y++;
        j++;
	}
}
void	ft_mini_map(t_game *game)
{
	ft_print_back_ground(game);
	ft_print_minimap(game);
	draw_axis(game, (M_PI / 4));
	draw_axis(game, (M_PI / 4) * -1);
	ft_draw_player(game, (MP_HEIGHT / 2), (MP_WIDTH / 2), game->mp_data.mp_player_color);
}