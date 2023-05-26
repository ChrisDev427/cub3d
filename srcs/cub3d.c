/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:00:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/26 11:50:02 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_get_map(argv[1], &game);
		ft_print_strs_array(game.parse.map);
		
		// mlx_key_hook(game.win.win_ptr, ft_keymap, &game);
		// ft_print_map(&game);
		// mlx_hook(game.win.win_ptr, 17, 0, ft_quit, &game);
		// mlx_loop(game.win.mlx_ptr);
	}
	else
		ft_error(&game, "Invalid arguments number\n");
	return (0);
}
