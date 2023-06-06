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

typedef struct	s_ray
{
	double		posx; //position x du joueur
	double		posy; //position y du joueur
	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int			mapx; // coordonée x du carré dans lequel est pos
	int			mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int			stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int			stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int			hit; // 1 si un mur a ete touche, 0 sinon
	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int			lineheight; //hauteur de la ligne a dessiner
	int			drawstart; //position de debut ou il faut dessiner
	int			drawend; //position de fin ou il faut dessiner
	int			x; //permet de parcourir tous les rayons
}					t_ray;

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
	char	**mapcpy;

}				t_parsing;

typedef struct s_data
{
	char	**elements;
	int		ceiling[4];
	int		floor[4];
	int		fl_color;
	int		ce_color;
	// int		minimap_y;
	// int		minimap_x;

	int		mini_map_bg[4];
	int		mini_map_walls[4];
	int		mini_map_floor[4];
	int		mp_bg_color;
	int		mp_walls_color;
	int		mp_floor_color;

}				t_data;

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
	float	moves[4];
	int		camera[2];
	float	degrees;
	float	pos_x;
	float	pos_y;
	int		player_x;
	int		player_y;

}				t_moves;

typedef struct s_images
{
	t_img minimap_img;
	t_img game_img;
	t_img ray_img;
	t_img title_img;

}				t_images;

typedef struct s_game
{
	t_parsing	parse;
	t_window	win;
	t_moves		mov;
	t_data		data;
	t_images	image;
	t_ray		ray;
}				t_game;



#endif