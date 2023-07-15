/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:00:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/15 07:43:18 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_check_ext(argv[1]);
		game.map = ft_get_map(&game, argv[1], game.map);
		ft_split_map_elem(&game);
		ft_check_map(&game);
		ft_get_colors(&game);
		ft_init(&game);
		ft_init_textures(&game);
		ft_position_direction(&game);
		ft_init_images(&game);
		mlx_key_hook(game.win.win, ft_keypress, &game);
		mlx_hook(game.win.win, 2, 0, ft_keypress, &game);
		mlx_hook(game.win.win, 3, 0, ft_keyrelease, &game);
		mlx_hook(game.win.win, 17, 0, ft_quit, &game);
		mlx_loop_hook(game.win.mlx, ft_run, &game);
		mlx_loop(game.win.mlx);
	}
	else
		ft_error(&game, "Invalid arguments number\n", NULL);
	return (0);
}
