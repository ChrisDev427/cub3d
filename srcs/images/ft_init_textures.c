/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:11:00 by chris             #+#    #+#             */
/*   Updated: 2023/07/12 16:34:19 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_init_textures(t_game *game)
{
    int width = 500;
    int height = 500;
    int i;

    i = 0;
    while (i < 4)
    {
        game->elem[i] = &game->elem[i][ft_str_chr(game->elem[i], '.')];
        game->image.tex[i].img = mlx_xpm_file_to_image(game->win.mlx,
            game->elem[i], &width, &height);
        if (!game->image.tex[i].img)
            ft_error(game, game->elem[i], " not valid texture file");
        game->image.tex[i].addr = mlx_get_data_addr(game->image.tex[i].img,
            &game->image.tex[i].bits_per_pixel, &game->image.tex[i].line_length,
                &game->image.tex[i].endian);
        game->image.img_data[i] = (unsigned int*)game->image.tex[i].addr;
        i++;
    }
}