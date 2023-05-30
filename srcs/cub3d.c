/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:00:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/30 19:34:32 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_init(&game);
		ft_get_map(argv[1], &game);
		ft_split_map_elem(&game);
		ft_check_map(&game);

		ft_get_colors(&game);
	
		// ft_print_strs_array(game.parse.elements);
		// puts("--------------------------------------------------------------------");
		ft_print_strs_array(game.parse.map);
		ft_player_position(&game);

		mlx_key_hook(game.win.win_ptr, ft_keypress, &game);
		// ft_print_map(&game);
		mlx_hook(game.win.win_ptr, 2, 0, ft_keypress, &game);
		mlx_hook(game.win.win_ptr, 3, 0, ft_keyrelease, &game);
		mlx_hook(game.win.win_ptr, 17, 0, ft_quit, &game);
		mlx_loop_hook(game.win.mlx_ptr, ft_run, &game);
		
		mlx_loop(game.win.mlx_ptr);
	}
	else
		ft_error(&game, "Invalid arguments number\n", NULL);
	return (0);
}
