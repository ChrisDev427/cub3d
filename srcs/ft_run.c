/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/15 16:15:13 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// #define screenWidth 1920
// #define screenHeight 1080
// #define mapWidth 24
// #define mapHeight 24



// void	ft_raycasting(t_game *game)
// {
// 	game->ray.x = 0;
// 	//double ratio = 0;
// 	//printf("win x = %d\n", game->win.x);
// 	// game->ray.posx = game->mov.pos_x;
// 	// game->ray.posy = game->mov.pos_y;
// 	game->ray.posx = game->player_x;
// 	game->ray.posy = game->player_y;
// 	game->ray.dirx = -1;
// 	game->ray.diry = 0;
// 	game->ray.planx = 0;
// 	game->ray.plany = 0.66;
// 	//printf("position x = %f\n", game->ray.posx);
// 	//printf("position y = %f\n", game->ray.posy);
// 	while (game->ray.x < SCREEN_WIDTH)
// 	{
// 		// ratio = (game->ray.x - (SCREEN_WIDTH / 2));
// 		// ratio /= SCREEN_WIDTH / 2;
// 		game->ray.camerax = 2 * game->ray.x / (double)SCREEN_WIDTH - 1;
// 		game->ray.raydirx = game->ray.dirx + game->ray.planx * game->ray.camerax;
// 		game->ray.raydiry = game->ray.diry + game->ray.plany * game->ray.camerax;
// 		game->ray.mapx = (int)game->ray.posx;
// 		game->ray.mapy = (int)game->ray.posy;
// 		// game->ray.dirx = (cos(game->rad)) + cos(game->rad) * ratio;
// 		// game->ray.diry = (sin(game->rad)) + sin(game->rad) * ratio;
// 		if (game->ray.raydirx == 0)
// 			game->ray.deltadistx = 1e30;
// 		else
// 			game->ray.deltadistx = sqrt(1 + (game->ray.diry * game->ray.diry) / (game->ray.dirx * game->ray.dirx));

// 		if (game->ray.raydiry == 0)
// 			game->ray.deltadisty = 1e30;
// 		else
// 			game->ray.deltadisty = sqrt(1 + (game->ray.dirx * game->ray.dirx) / (game->ray.diry * game->ray.diry));
// 		// double deltaDistX = (game->ray.raydirx == 0) ? 1e30 : abs(1 / game->ray.raydirx);
//     	// double deltaDistY = (game->ray.raydiry == 0) ? 1e30 : abs(1 / game->ray.raydiry);
// 		// printf("position x = %f\n", game->ray.dirx);
// 		// printf("position y = %f\n", game->ray.diry);
// 		// exit(1);
// 		if (game->ray.dirx < 0)
// 		{
// 			game->ray.stepx = -1;
// 			game->ray.sidedistx = (game->ray.posx - game->ray.mapx) * game->ray.deltadistx;
// 		}
// 		else
// 		{
// 			game->ray.stepx = 1;
// 			game->ray.sidedistx = (game->ray.mapx + 1 - game->ray.posx) * game->ray.deltadistx;
// 		}
// 		if (game->ray.diry < 0)
// 		{
// 			game->ray.stepy = -1;
// 			game->ray.sidedisty = (game->ray.posy - game->ray.mapy) * game->ray.deltadisty;
// 		}
// 		else
// 		{
// 			game->ray.stepy = 1;
// 			game->ray.sidedisty = (game->ray.mapy + 1 - game->ray.posy) * game->ray.deltadisty;
// 		}
// 		game->ray.hit = 0;
// 		while (game->ray.hit == 0)
// 		{
// 			if (game->ray.sidedistx < game->ray.sidedisty) //game->ray.sidedisty <= 0 || (game->ray.sidedistx >= 0 &&
// 			{
// 				game->ray.sidedistx += game->ray.deltadistx;
// 				game->ray.mapx += game->ray.stepx;
// 				game->ray.side = 0;
// 			}
// 			else
// 			{
// 				game->ray.sidedisty += game->ray.deltadisty;
// 				game->ray.mapy += game->ray.stepy;
// 				game->ray.side = 1;
// 			}
// 		if (game->mapcpy[game->ray.mapx][game->ray.mapy] == '1')
// 			game->ray.hit = 1;
// 		// printf("mapx = %d\n",game->ray.mapx);
// 		// printf("mapy = %d\n",game->ray.mapy);
// 		// printf("chiffre = %c\n",game->mapcpy[game->ray.mapx][game->ray.mapy]);
// 			//printf("mapX = %d\n", game->ray.mapx);
// 			//printf("mapY = %d\n", game->ray.mapy);
// 			//printf("hit = %d\n", game->ray.hit);
// 		}
// 		if (game->ray.side == 0)
// 		{
// 			game->ray.perpwalldist = game->ray.sidedistx - game->ray.deltadistx; //(game->ray.mapx - game->ray.posx + ((1 + game->ray.stepx) / 2) / game->ray.dirx);
// 		}
// 		else
// 			game->ray.perpwalldist = game->ray.sidedisty - game->ray.deltadisty; //(game->ray.mapy - game->ray.posy + ((1 + game->ray.stepy) / 2) / game->ray.diry);
// 		game->ray.lineheight = (int)(SCREEN_HEIGHT / game->ray.perpwalldist);
// 		game->ray.drawstart = -game->ray.lineheight / 2 + SCREEN_HEIGHT / 2;
// 		if (game->ray.drawstart < 0)
// 			game->ray.drawstart = 0;
// 		game->ray.drawend = game->ray.lineheight / 2 + SCREEN_HEIGHT / 2;
// 		if (game->ray.drawend >= game->ray.lineheight)
// 			game->ray.drawstart = game->ray.lineheight - 1;

// 		printf("distance du mur = %f\n", game->ray.perpwalldist);
// 		printf("hauteur ligne = %d\n", game->ray.lineheight);
// 		printf("start = %d\n", game->ray.drawstart);
// 		printf("end = %d\n", game->ray.drawend);
// 		// exit(1);
// 		while (game->ray.drawend >= game->ray.drawstart)
// 		{
// 			if (game->ray.side == 1)
// 				ft_my_mlx_pixel_put(&game->image.game_img, game->ray.x, game->ray.drawend, 0xFFFFFF);
// 			else
// 				ft_my_mlx_pixel_put(&game->image.game_img, game->ray.x, game->ray.drawend, 0xFFFFFF / 2);
// 			//mlx_pixel_put(game->win.mlx, game->win.win, game->ray.drawstart, game->ray.drawend, 0xFFFFFF);
// 			game->ray.drawend--;
// 		}
// 		game->ray.x++;
// 	}
//     	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.game_img.img, 0, 0);
// }

int    ft_run(t_game *game)
{
    if (game->data.frame == 100)
        game->data.frame = 0;
    game->data.frame++;

	mlx_clear_window(game->win.mlx, game->win.win); // Efface la fenêtre
   	ft_print_floor_ceiling(game);
    ft_mini_map(game);
   

    ft_player_moves(game);
    ft_camera(game);
    
    
    ft_raycasting_test(game);
    ft_print_specs(game);

    // if (game->data.frame % 2 == 1)
	ft_title(game);
    mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.game_img.img, 0, 0);
	mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, MP_POS_HEIGHT, MP_POS_WIDTH);
    return (0);
}