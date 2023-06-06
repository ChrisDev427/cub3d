/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/01 13:57:04 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	// int		size_x;
	// int		size_y;
	
}				t_window;

typedef struct s_parsing
{
	int		fd;
	char	**map;
	char	*elem_token[7];
	int		map_nb_lines;
	int		map_lines_len;
	char	**maptmp;
	char	**mapcpy;

}				t_parsing;

typedef struct s_data
{
	char	**elements;
	int		ceiling[4];
	int		floor[4];
	int		fl_color;
	int		ce_color;
	int		x;
	int		y;
	int		frame;
}				t_data;

typedef struct s_mp_data
{
	//--- minimap data  ------------
	int		mini_map_bg[4];
	int		mini_map_walls[4];
	int		mini_map_floor[4];
	int		mini_map_player[4];
	int		mini_map_border[4];
	int		mp_bg_color;
	int		mp_walls_color;
	int		mp_floor_color;
	int		mp_player_color;
	int		mp_border_color;
	int		y_tmp;
	int		x_tmp;
	int		y_mp;
	int		x_mp;
}				t_mp_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	pixel_offset;
}				t_img;

typedef struct s_moves
{
	int		moves[4];
	int		camera[2];		
	int		degrees;
	char	*str_deg;
	float	mp_pos_x;
	float	mp_pos_y;
	int		player_x;
	int		player_y;

}				t_moves;

typedef struct s_images
{
	t_img minimap_img;
	t_img game_img;
	t_img title_img;

}				t_images;

typedef struct s_game
{
	t_parsing	parse;
	t_window	win;
	t_moves		mov;
	t_data		data;
	t_mp_data	mp_data;
	t_images	image;
}				t_game;



#endif