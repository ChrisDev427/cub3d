/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:43:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/11 15:19:22 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_draw_tex(t_game *game, int start, int end)
{
    //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if (game->rc.side == 0)
        wallX = game->pos_y + game->rc.perp_wall_dist * game->rc.ray_dir_y;
      else
        wallX = game->pos_x + game->rc.perp_wall_dist * game->rc.ray_dir_x;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (wallX * 500.00);
      if(game->rc.side == 0 && game->rc.ray_dir_x > 0)
        texX = 500 - texX - 1;
      if(game->rc.side == 1 && game->rc.ray_dir_y < 0)
        texX = 500 - texX - 1;

         // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * 500.00 / game->image.tex[0].line_length;
      // Starting texture coordinate
      double texPos = (start - SCREEN_HEIGHT / 2 + (end - start) / 2) * step;
      for(int y = start; y < end; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (500 - 1);
        texPos += step;
        unsigned int *img_data = (unsigned int *)mlx_get_data_addr(game->image.tex[0].img, &game->image.tex[0].bits_per_pixel, &game->image.tex[0].line_length, &game->image.tex[0].endian);
        unsigned int color = img_data[texY * (game->image.tex[0].line_length / 4) + texY];
        //unsigned int *img_add = mlx_get_data_addr(game->)
        ft_my_mlx_pixel_put(&game->image.game_img , game->rc.ray_x, y, color);
      }
}

void    ft_vertical_draw(t_game *game, int start, int end)
{
    int y = 0;
    while (y < SCREEN_HEIGHT)
    {
        if (y < start)
            ft_my_mlx_pixel_put(&game->image.game_img , game->rc.ray_x, y, game->data.ce_color);
        if (y > end)
            ft_my_mlx_pixel_put(&game->image.game_img, game->rc.ray_x, y, game->data.fl_color);
        y++;
    }
    ft_draw_tex(game, start, end);
}

