/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/20 09:58:51 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "cub3d_structs.h"
# include "cub3d_defines.h"
# include "../libft/libft.h"
# include "mlx.h"
# include "string.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

//-----------------------------------------------------------------------------
//******** parsing functions **************************************************
//-----------------------------------------------------------------------------
void 	ft_open(char *file, int *fd);
char    **ft_get_map(char *file, char **tab);
// void    ft_get_map(char *file, t_game *game);
void	ft_split_map_elem(t_game *game);
void	ft_check_map(t_game *game);
void	ft_error(t_game *game, char *s1, char *s2);
// void	ft_window(t_game *game);
void	ft_init(t_game *game);
void    ft_init_images(t_game *game);
void    ft_get_colors(t_game *game);
// void	ft_minimap_size(t_game *game);
int     ft_set_map_cpy(t_game *game);
void    ft_enlarge_map(t_game *game);
void	ft_check_ext(char *file);
//-----------------------------------------------------------------------------
//******** game functions *****************************************************
//-----------------------------------------------------------------------------
void    ft_position_direction(t_game *game);
int     ft_color_to_int(int *tab_color);
void    ft_print_floor_ceiling(t_game *game);
void	ft_my_mlx_pixel_put(t_img *img, int x, int y, int color);
void    ft_print_specs(t_game *game);
void	rotate_axis(t_game *game);
void    ft_raycasting_test(t_game *game);
void    ft_rotate_right(t_game *game);
void    ft_rotate_left(t_game *game);
void    ft_vertical_draw(t_game *game, int start, int end, int color);

//-----------------------------------------------------------------------------
//******** events functions ***************************************************
//-----------------------------------------------------------------------------
int		ft_quit(t_game *game);
int		ft_keypress(int key, t_game *game);
int		ft_keyrelease(int key, t_game *game);
int     ft_run(t_game *game);
void    ft_camera(t_game *game);
void    ft_title(t_game *game);
void    ft_player_moves(t_game *game);
//-----------------------------------------------------------------------------
//******** minimap functions **************************************************
//-----------------------------------------------------------------------------
void	ft_mini_map(t_game *game);
void	ft_minimap_init(t_game *game);
void	ft_print_back_ground(t_game *game);
void	ft_draw_player(t_game *game, int y, int x, int color);
void	draw_axis(t_game *game, double pos,double posy, int needle_length);

#endif