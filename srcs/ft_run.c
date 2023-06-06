/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/06 15:44:46 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycasting(t_game *game)
{
	game->ray.x = 0;
	double ratio = 0;
	//printf("win x = %d\n", game->win.x);
	game->ray.posx = game->mov.pos_x;
	game->ray.posy = game->mov.pos_y;
	while (game->ray.x < 1920)
	{
		ratio = (game->ray.x - (1920 / 2));
		ratio /= 1920 / 2;
		game->ray.dirx = (cos(game->mov.degrees / 2)) + cos(game->mov.degrees - 0.25) * ratio;
		game->ray.diry = (sin(game->mov.degrees / 2)) + sin(game->mov.degrees - 0.25) * ratio;
		game->ray.mapx = floor(game->ray.posx);
		game->ray.mapy = floor(game->ray.posy);
		game->ray.deltadistx = sqrt(1 + ((game->ray.diry * game->ray.diry) / game->ray.dirx * game->ray.dirx));
		game->ray.deltadisty = sqrt(1 + ((game->ray.dirx * game->ray.dirx) / game->ray.diry * game->ray.diry));

		if (game->ray.dirx < 0)
		{
			game->ray.stepx = -1;
			game->ray.sidedistx = (game->ray.x - game->ray.mapx) * game->ray.deltadistx;
		}
		else
		{
			game->ray.stepx = 1;
			game->ray.sidedistx = (game->ray.mapx + 1) * game->ray.deltadistx;
		}
		if (game->ray.diry < 0)
		{
			game->ray.stepy = -1;
			game->ray.sidedisty = (game->ray.x - game->ray.mapy) * game->ray.deltadisty;
		}
		else
		{
			game->ray.stepy = 1;
			game->ray.sidedisty = (game->ray.mapy + 1) * game->ray.deltadisty;
		}
		game->ray.hit = 0;
		while (!game->ray.hit)
		{
			if (game->ray.sidedisty <= 0 || (game->ray.sidedistx >= 0 && game->ray.sidedistx < game->ray.sidedisty))
			{
				game->ray.sidedistx += game->ray.deltadistx;
				game->ray.mapx += game->ray.stepx;
				game->ray.side = 0;
			}
			else
			{
				game->ray.sidedisty += game->ray.deltadisty;
				game->ray.mapy += game->ray.stepy;
				game->ray.side = 1;
			}
		}
		if (strcmp(&game->parse.map[game->ray.mapy][game->ray.mapx], "0") != 0)
			game->ray.hit = 1;
		if (game->ray.side == 0)
		{
			game->ray.perpwalldist = (game->ray.mapx - game->ray.posx + ((1 + game->ray.stepx) / 2) / game->ray.dirx);
		}
		else
			game->ray.perpwalldist = (game->ray.mapy - game->ray.posy + ((1 + game->ray.stepy) / 2) / game->ray.diry);
		game->ray.lineheight = (1920 / 2);
		game->ray.drawstart = (1080 / 2) - game->ray.perpwalldist;
		game->ray.drawend = (1080 / 2) + game->ray.perpwalldist;
		while (game->ray.drawstart < game->ray.drawend)
		{
			ft_my_mlx_pixel_put(&game->image.game_img, game->ray.x, game->ray.lineheight, 0xFFFFFF);
			//mlx_pixel_put(game->win.mlx, game->win.win, game->ray.drawstart, game->ray.drawend, 0xFFFFFF);
			game->ray.drawstart++;
		}
		game->ray.x++;
	}
    	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.game_img.img, game->ray.drawstart, game->ray.drawend);
}

int    ft_run(t_game *game)
{
    // ft_print_floor_ceiling(game);
    ft_camera(game);
	ft_raycasting(game);

    return (0);
}