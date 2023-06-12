/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/12 22:44:23 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// #define screenWidth 1920
// #define screenHeight 1080
// #define mapWidth 24
// #define mapHeight 24

// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };


// void	ft_raycasting(t_game *game)
// {
// 	game->ray.x = 0;
// 	double ratio = 0;
// 	//printf("win x = %d\n", game->win.x);
// 	// game->ray.posx = game->mov.pos_x;
// 	// game->ray.posy = game->mov.pos_y;
// 	game->ray.posx = 22;
// 	game->ray.posy = 12;
// 	game->ray.dirx = -1;
// 	game->ray.diry = 0;
// 	game->ray.planx = 0;
// 	game->ray.plany = 0.66;
// 	//printf("position x = %f\n", game->ray.posx);
// 	//printf("position y = %f\n", game->ray.posy);
// 	while (game->ray.x < 1920)
// 	{
// 		//ratio = (game->ray.x - (1920 / 2));
// 		//ratio /= 1920 / 2;
// 		//game->ray.camerax = 2 * game->ray.x /
// 		game->ray.dirx = (cos(game->mov.degrees * (M_PI / 180) / 2)) + cos(game->mov.degrees - 0.25) * ratio;
// 		game->ray.diry = (sin(game->mov.degrees * (M_PI / 180) / 2)) + sin(game->mov.degrees - 0.25) * ratio;
// 		game->ray.mapx = (int)game->ray.posx;
// 		game->ray.mapy = (int)game->ray.posy;
// 		game->ray.deltadistx = sqrt(1 + (game->ray.diry * game->ray.diry) / (game->ray.dirx * game->ray.dirx));
// 		game->ray.deltadisty = sqrt(1 + (game->ray.dirx * game->ray.dirx) / (game->ray.diry * game->ray.diry));
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
// 		while (!game->ray.hit)
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
// 			if (worldMap[game->ray.mapx][game->ray.mapy] > 1)
// 			game->ray.hit = 1;
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
// 		game->ray.lineheight = (int)(1080 / game->ray.perpwalldist);
// 		game->ray.drawstart = -game->ray.lineheight / 2 + 1080 / 2;
// 		if (game->ray.drawstart < 0)
// 			game->ray.drawstart = 0;
// 		game->ray.drawend = game->ray.lineheight / 2 + 1080 / 2;
// 		if (game->ray.drawend >= game->ray.lineheight)
// 			game->ray.drawstart = game->ray.lineheight - 1;
// 		// printf("distance du mur = %f\n", game->ray.perpwalldist);
// 		// printf("hauteur ligne = %d\n", game->ray.lineheight);
// 		// printf("start = %d\n", game->ray.drawstart);
// 		// printf("end = %d\n", game->ray.drawend);
// 		// exit(1);
// 		while (game->ray.drawend > game->ray.drawstart)
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
	//printf("rad = %f\n", game->mov.rad);
    // if (game->data.frame == 200)
    //     game->data.frame = 0;
    // game->data.frame++;
    //ft_print_floor_ceiling(game);
    // if (game->data.frame % 6 == 1)
    ft_camera(game);
    ft_moves(game);
    ft_mini_map(game);
    //if (game->data.frame % 8 == 1)
    // printf("%f\n", game->mov.degrees);
    // printf("%d\n", game->data.frame);
	//ft_title(game);
    //ft_print_specs(game);
	//mlx_put_image_to_window(game->win.mlx, game->win.win, game->image.minimap_img.img, 35, 35);
    
    return (0);
}