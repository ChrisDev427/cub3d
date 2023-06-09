/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:00:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/09 17:03:31 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	

	if (argc == 2)
	{
		ft_init(&game);
		ft_check_ext(argv[1]);
		
		game.parse.map = ft_get_map(argv[1], game.parse.map);
		// ft_print_strs_array(game.parse.map);
		ft_split_map_elem(&game);
		ft_check_map(&game);
    	// ft_print_strs_array(game.parse.maptmp);

		// ft_print_strs_array(game.parse.map);
		ft_player_position(&game);
	
    	ft_print_strs_array(game.parse.mapcpy);
	
		ft_get_colors(&game);
		ft_init_images(&game);
       
		
   		// ft_print_floor_ceiling(&game);
		
		// ft_init_minimap(&game);
		// ft_mini_map(&game);
		
		// puts("--------------------------------------------------------------------");

		mlx_key_hook(game.win.win, ft_keypress, &game);
		// ft_print_map(&game);
		// ft_mini_map(&game);

		mlx_hook(game.win.win, 2, 0, ft_keypress, &game);
		mlx_hook(game.win.win, 3, 0, ft_keyrelease, &game);
		mlx_hook(game.win.win, 17, 0, ft_quit, &game);
		mlx_loop_hook(game.win.mlx, ft_run, &game);

		
		// ft_title(&game);
		mlx_loop(game.win.mlx);
	}
	else
		ft_error(&game, "Invalid arguments number\n", NULL);
	return (0);
}
