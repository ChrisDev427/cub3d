/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/30 19:34:16 by chmassa          ###   ########.fr       */
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
	void	*mlx_ptr;
	void	*win_ptr;
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
	char	**elements;
	char	*elem_token[7];
	char	**mapcpy;

	int		ceiling[4];
	int		floor[4];
}				t_parsing;
//-----------------------------------------------------------------------------
//********* images struct *****************************************************
//-----------------------------------------------------------------------------
typedef struct s_moves
{
	float	moves[4];
	int		camera[2];		
	float	degrees;
	float	pos_x;
	float	pos_y;
	int		player_x;
	int		player_y;

	// void	*exit;
	// void	*wall;
	// void	*ruby;
	// void	*floor;
	// void	*link_face;
	// void	*link_back;
	// void	*link_left;
	// void	*link_right;
}				t_moves;
typedef struct s_game
{
	t_parsing	parse;
	t_window	win;
	t_moves		mov;
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
void    ft_get_colors(t_game *game);
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