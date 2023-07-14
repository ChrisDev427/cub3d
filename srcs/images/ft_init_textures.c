/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:11:00 by chris             #+#    #+#             */
/*   Updated: 2023/07/14 18:41:48 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_rev(t_game *game, int tex)
{
	game->rev.i = 0;
	game->rev.src_i = (game->rev.y * game->image.tex[tex].line_length)
		+ (game->rev.x * (game->image.tex[tex].bits_per_pixel / 8));
	game->rev.dest_i = (game->rev.y * game->image.tex[tex].line_length)
		+ ((game->rc.tex_size_w - game->rev.x - 1)
			* (game->image.tex[tex].bits_per_pixel / 8));
	while (game->rev.i++ < (game->image.tex[tex].bits_per_pixel / 8))
		game->rev.rev_data[game->rev.dest_i + game->rev.i]
			= game->image.tex[tex].addr[game->rev.src_i + game->rev.i];
}

static void	ft_reverse_pixels(t_game *game, int tex)
{
	game->rev.y = 0;
	// game->rev.rev_data = (char *)malloc(game->image.tex[tex].line_length
	// 		* game->rc.tex_size_h);
	game->rev.rev_data = ft_calloc(game->image.tex[tex].line_length, game->rc.tex_size_h);
	while (game->rev.y < game->rc.tex_size_h)
	{
		game->rev.x = 0;
		while (game->rev.x < game->rc.tex_size_w)
		{
			ft_rev(game, tex);
			game->rev.x++;
		}
		game->rev.y++;
	}
	free(game->image.tex[tex].addr);
	game->image.tex[tex].addr = game->rev.rev_data;
}

static void	ft_check_size(t_game *game, int size_tmp, int i)
{
	if (game->rc.tex_size_w != game->rc.tex_size_h)
		ft_error(game, game->elem[i], " texture size must be squared");
	if (game->rc.tex_size_w != size_tmp)
		ft_error(game, game->elem[i], " all textures must have same size");
}

void	ft_init_textures(t_game *game)
{
	int	i;
	int	size_tmp;

	i = 0;
	while (i < 4)
	{
		game->elem[i] = &game->elem[i][ft_str_chr(game->elem[i], '.')];
		game->image.tex[i].img = mlx_xpm_file_to_image(game->win.mlx,
				game->elem[i], &game->rc.tex_size_w, &game->rc.tex_size_h);
		if (!game->image.tex[i].img)
			ft_error(game, game->elem[i], " not valid texture file");
		if (i == 0)
			size_tmp = game->rc.tex_size_w;
		ft_check_size(game, size_tmp, i);
		game->image.tex[i].addr = mlx_get_data_addr(game->image.tex[i].img,
				&game->image.tex[i].bits_per_pixel,
				&game->image.tex[i].line_length, &game->image.tex[i].endian);
		if (i == 1 || i == 2)
			ft_reverse_pixels(game, i);
		game->image.img_data[i] = (unsigned int *)game->image.tex[i].addr;
		i++;
	}
}
