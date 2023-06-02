/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:29:27 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/02 14:15:46 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


// void	ft_my_mlx_pixel_put(t_game *game, char *addr, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = addr + (y * game->data.line_length + x * (game->data.bits_per_pixel / 8));
// 	*(unsigned int*)dst = (unsigned int)color;
// }
void	ft_my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = (unsigned int)color;
}