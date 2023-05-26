/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/26 12:04:20 by chmassa          ###   ########.fr       */
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
	int		px;
	int		py;
	int		collectibles_nbr;
	int		collected;
	void	*img;
	int		img_wh;
	int		img_ht;
}				t_window;
//-----------------------------------------------------------------------------
//********* parsing struct ****************************************************
//-----------------------------------------------------------------------------
typedef struct s_parsing
{
	int		fd;
	char	**map;
	char	*elements[7];
	char	**mapcpy;
}				t_parsing;
//-----------------------------------------------------------------------------
//********* images struct *****************************************************
//-----------------------------------------------------------------------------
typedef struct s_sprites
{
	int		moves;
	void	*exit;
	void	*wall;
	void	*ruby;
	void	*floor;
	void	*link_face;
	void	*link_back;
	void	*link_left;
	void	*link_right;
}				t_sprites;
typedef struct s_game
{
	t_parsing	parse;
	t_window	win;
	t_sprites	img;
}				t_game;
//-----------------------------------------------------------------------------
//******** parsing functions **************************************************
//-----------------------------------------------------------------------------
void	ft_open(char *file, int *fd);
void	ft_get_map(char *file, t_game *game);
void	ft_get_elements(t_game *game);
void	ft_check_map_basics(t_game *game);
void	ft_error(t_game *game, char *s);
void	ft_window(t_game *game);
void	ft_initial(t_game *game);
//-----------------------------------------------------------------------------
//******** mapping ************************************************************
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//******** events functions ***************************************************
//-----------------------------------------------------------------------------
int		ft_quit(t_game *game);
int		ft_keymap(int key, t_game *game);
void	ft_print_map(t_game *game);
#endif