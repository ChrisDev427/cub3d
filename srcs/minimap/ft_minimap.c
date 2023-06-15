#include "../../includes/cub3d.h"

void	draw_axis(t_game *game, double pos, int needle_length)
{
	game->end_needle_x = game->ppos_x - (int)(needle_length
		* sin(game->rad + pos));
	game->end_needle_y = game->ppos_y - (int)(needle_length
		* cos(game->rad + pos));
	game->dx = game->end_needle_x - game->ppos_x;
	game->dy = game->end_needle_y - game->ppos_y;
	if (abs(game->dx) > abs(game->dy))
    	game->steps = abs(game->dx);
	else 
    	game->steps = abs(game->dy);
	game->x_increment = (float)game->dx / (float)game->steps;
	game->y_increment = (float)game->dy / (float)game->steps;
	game->pos_x = (MP_WIDTH / 2 + 10);
	game->pos_y = (MP_HEIGHT / 2 + 10);
	game->i = 0;
	while (game->i <= game->steps)
	{
		game->pos_x += game->x_increment;
		game->pos_y += game->y_increment;
		ft_my_mlx_pixel_put(&game->image.minimap_img,
			game->pos_x, game->pos_y, 0x63EFF00);
		game->i++;
	}
}


static void	ft_print_minimap(t_game *game)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	y = game->ppos_y - (MP_HEIGHT /2);
	while (i < MP_HEIGHT)
	{
		j = 0;
		x = game->ppos_x - (MP_WIDTH /2);
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
	}
}
void	ft_mini_map(t_game *game)
{
	ft_print_back_ground(game);
	ft_print_minimap(game);
	// draw_axis(game, (M_PI / 4));
	// draw_axis(game, (M_PI / 4) * -1);

	draw_axis(game, (-M_PI/2), 150);
	draw_axis(game, -M_PI/2 -M_PI /5.5, 30);
	draw_axis(game, -M_PI/2 -M_PI /5.5 * -1, 30);
	ft_draw_player(game, (MP_HEIGHT / 2), (MP_WIDTH / 2), game->mp_data.mp_player_color);
}