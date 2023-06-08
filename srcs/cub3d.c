/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:00:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/08 14:46:15 by axfernan         ###   ########.fr       */
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
    	// ft_print_strs_array(game.parse.maptmp);
    	// ft_print_strs_array(game.parse.mapcpy);

		// ft_print_strs_array(game.parse.map);
		ft_player_position(&game);
		ft_get_colors(&game);
		ft_init_images(&game);


   		ft_print_floor_ceiling(&game);
		// ft_init_minimap(&game);
		// ft_mini_map(&game);

		// puts("--------------------------------------------------------------------");

		mlx_key_hook(game.win.win, ft_keypress, &game);
		//ft_print_map(&game);
		// for (int i = 0; game.parse.map[i]; i++)
		// 	printf("%s\n", game.parse.map[i]);
		mlx_hook(game.win.win, 2, 0, ft_keypress, &game);
		mlx_hook(game.win.win, 3, 0, ft_keyrelease, &game);
		mlx_hook(game.win.win, 17, 0, ft_quit, &game);
		t_vars vars;

		vars.center_x = 400; // Position x du centre de rotation de l'aiguille
		vars.center_y = 300; // Position y du centre de rotation de l'aiguille
		vars.rotation_angle = 0;
		mlx_loop_hook(game.win.mlx, ft_run, &game);


		// ft_title(&game);
		mlx_loop(game.win.mlx);
	}
	else
		ft_error(&game, "Invalid arguments number\n", NULL);
	return (0);
}
