/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/14 12:31:12 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_window;

typedef struct s_rev_pix
{
	int		i;
	int		x;
	int		y;
	int		src_i;
	int		dest_i;
	char	*rev_data;
}				t_rev_pix;

typedef struct s_data
{
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
	int		mp_bg[4];
	int		mp_walls[4];
	int		mp_overmap[4];
	int		mp_player[4];
	int		bg_cl;
	int		walls_cl;
	int		over_cl;
	int		pl_cl;
}				t_mp_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		pixel_offset;
}				t_img;

typedef struct s_images
{
	t_img			minimap;
	t_img			game_img;
	t_img			title;
	t_img			tex[4];

	unsigned int	*img_data[4];
}				t_images;

typedef struct s_raycasting
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	oldtime;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		ray_dist;
	int		ray_x;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	double	rot_speed;
	double	move_speed;
	double	ratio;
	double	wallx;
	int		y_draw;
	double	tex_y;
	int		tex;
	int		tex_size_w;
	int		tex_size_h;
}				t_raycasting;

typedef struct s_game
{
	int				fd;
	char			**map;
	char			**elem;
	char			*elem_token[7];
	int				map_nb_lines;
	int				map_lines_len;
	char			**maptmp;
	char			**mapcpy;
	int				moves[4];
	int				camera[2];
	int				slow;
	int				fast;
	char			*state;
	float			rad;
	double			fpos_x;
	double			fpos_y;
	int				ipos_x;
	int				ipos_y;
	int				ppos_x;
	int				ppos_y;
	int				i;
	int				start_needle_x;
	int				start_needle_y;
	int				end_needle_x;
	int				end_needle_y;
	int				dx;
	int				dy;
	float			pos_x;
	float			pos_y;
	float			x_increment;
	float			y_increment;
	int				steps;
	int				needle_length;
	t_window		win;
	t_data			data;
	t_mp_data		mp;
	t_images		image;
	t_raycasting	rc;
	t_rev_pix		rev;
}				t_game;
#endif