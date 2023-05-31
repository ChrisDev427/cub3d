/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/31 16:08:10 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "mlx.h"
# include "string.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>


//-----------------------------------------------------------------------------
//********* window struct *****************************************************
//-----------------------------------------------------------------------------
typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	
}				t_window;
//-----------------------------------------------------------------------------
//********* parsing struct ****************************************************
//-----------------------------------------------------------------------------
typedef struct s_parsing
{
	int		fd;
	char	**map;
	char	*elem_token[7];
	char	**mapcpy;

}				t_parsing;
//-----------------------------------------------------------------------------
//********* images struct *****************************************************
//-----------------------------------------------------------------------------
typedef struct s_data
{
	char	**elements;
	int		ceiling[4];
	int		floor[4];
	int		fl_color;
	int		ce_color;
	int		minimap_y;
	int		minimap_x;
	void	*minimap_img;
	char	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int 	pixel_offset;

	int		mini_map_color[4];
	int		mini_map_floor[4];
	int		mini_map_walls[4];

	

}				t_data;

typedef struct s_moves
{
	float	moves[4];
	int		camera[2];		
	float	degrees;
	float	pos_x;
	float	pos_y;
	int		player_x;
	int		player_y;

}				t_moves;

typedef struct s_game
{
	t_parsing	parse;
	t_window	win;
	t_moves		mov;
	t_data		data;
}				t_game;
//-----------------------------------------------------------------------------
//******** parsing functions **************************************************
//-----------------------------------------------------------------------------
void	ft_open(char *file, int *fd);
void	ft_get_map(char *file, t_game *game);
void	ft_split_map_elem(t_game *game);
void	ft_check_map(t_game *game);
void	ft_error(t_game *game, char *s1, char *s2);
void	ft_window(t_game *game);
void	ft_init(t_game *game);
void    ft_init_minimap(t_game *game);
void    ft_get_colors(t_game *game);
void	ft_minimap_size(t_game *game);
void	ft_minimap_color_init(t_game *game);
//-----------------------------------------------------------------------------
//******** mapping ************************************************************
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//******** events functions ***************************************************
//-----------------------------------------------------------------------------
int		ft_quit(t_game *game);
int		ft_keypress(int key, t_game *game);
int		ft_keyrelease(int key, t_game *game);
void	ft_mini_map(t_game *game);
int     ft_run(t_game *game);
void    ft_camera(t_game *game);
void    ft_player_position(t_game *game);
#endif