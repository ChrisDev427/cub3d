/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:00:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/06 13:06:15 by axfernan         ###   ########.fr       */
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
		// ft_print_strs_array(game.parse.map);
		ft_player_position(&game);
		ft_get_colors(&game);
		ft_init_images(&game);


   		ft_print_floor_ceiling(&game);
		// ft_init_minimap(&game);
		ft_mini_map(&game);

		// ft_print_strs_array(game.parse.elements);
		// puts("--------------------------------------------------------------------");

		mlx_key_hook(game.win.win, ft_keypress, &game);
		//ft_print_map(&game);
		// for (int i = 0; game.parse.map[i]; i++)
		// 	printf("%s\n", game.parse.map[i]);
		mlx_hook(game.win.win, 2, 0, ft_keypress, &game);
		mlx_hook(game.win.win, 3, 0, ft_keyrelease, &game);
		mlx_hook(game.win.win, 17, 0, ft_quit, &game);
		mlx_loop_hook(game.win.mlx, ft_run, &game);
		ft_title(&game);
		mlx_loop(game.win.mlx);
	}
	else
		ft_error(&game, "Invalid arguments number\n", NULL);
	return (0);
}
