/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/15 08:46:23 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

//-- screen size --------------------------------
# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 850
//-- walls color --------------------------------
# define WALLS_NORTH 0x0039FF
# define WALLS_SOUTH 0x08FF00
# define WALLS_EAST 0xFF0000
# define WALLS_WEST 0xF7FF00
//-- speed --------------------------------------
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.01

//-- minimap back ground color ------------------
# define BG_COL_A 200
# define BG_COL_R 255
# define BG_COL_G 255
# define BG_COL_B 255

//-- over map color -----------------------------
# define OV_COL_A 190
# define OV_COL_R 225
# define OV_COL_G 0
# define OV_COL_B 0
//-- minimap walls color ------------------------
# define WL_COL_A 140
# define WL_COL_R 40
# define WL_COL_G 85
# define WL_COL_B 140
//-- minimap player color ------------------------
# define PL_COL_A 80
# define PL_COL_R 0
# define PL_COL_G 4
# define PL_COL_B 147
//-- minimap size -------------------------------
# define MP_WIDTH 400
# define MP_HEIGHT 240
//-- minimap position -------------------------------
# define MP_POS_WIDTH 30
# define MP_POS_HEIGHT (SCREEN_HEIGHT -MP_HEIGHT -30)

#endif