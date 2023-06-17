/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/17 09:42:52 by chris            ###   ########.fr       */
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
}				t_window;

// typedef struct s_parsing
// {
// 	int		fd;
// 	char	**map;
// 	char	*elem_token[7];
// 	int		map_nb_lines;
// 	int		map_lines_len;
// 	char	**maptmp;
// 	char	**mapcpy;
// }				t_parsing;

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
	int		mp_bg_color;
	int		mp_walls_color;
	int		mp_floor_color;
	int		mp_player_color;
	// int		y_tmp;
	// int		x_tmp;
	// int		y_mp;
	// int		x_mp;
}				t_mp_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	pixel_offset;
	void	*img_minimap_border;
}				t_img;


typedef struct s_images
{
	t_img minimap_img;
	t_img game_img;
	t_img title_img;
}				t_images;

typedef struct s_raycasting
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	
	double	time;
	double	oldtime;

	double camera_x;
    double ray_dir_x;
    double ray_dir_y;

	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;

	double	perp_wall_dist;

	int		ray_x;
	int		step_x;
    int		step_y;
	int		map_x;
	int		map_y;
    int		hit; //was there a wall hit?
    int		side; //was a NS or a EW wall hit?
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	double	rot_speed;
	double	move_speed;


}				t_raycasting;

typedef struct s_game
{
//---- parsing --------------------
	int		fd;
	char	**map;
	char	*elem_token[7];
	int		map_nb_lines;
	int		map_lines_len;
	char	**maptmp;
	char	**mapcpy;
//---- moves ---------------------
	int		moves[4];
	int		camera[2];
	int		slow;
	float	rad;
	double	fpos_x;
	double	fpos_y;
	int		ipos_x;
	int		ipos_y;
	int		ppos_x;
	int		ppos_y;
//--- axis data ------------------
	int		i;
	int		start_needle_x;
	int		start_needle_y;
	int		end_needle_x;
	int		end_needle_y;
	int		dx;
	int		dy;
	float	pos_x;
	float	pos_y;
	float	x_increment;
	float	y_increment;
	int 	steps;
	int		needle_length;

	t_window		win;
	t_data			data;
	t_mp_data		mp_data;
	t_images		image;
	t_raycasting	rc;
}				t_game;
#endif