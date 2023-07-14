/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 16:08:52 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	trigo_direction(t_game *game, double speed, double radians, int reverse)
// {
// 	double mov_playerx;
// 	double mov_playery;

// 	mov_playerx = (speed * cos(radians));
// 	mov_playery = (speed * sin(radians));
// 	game->fpos_x += (mov_playerx * reverse);
// 	game->fpos_y += (mov_playery * reverse);
// }

static void    ft_go_straight(t_game *game)
{
    if (game->rc.dir_x >= 0)
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)] != '1' && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x + 0.5)] != '1')
            game->fpos_x += game->rc.dir_x * game->rc.move_speed;
    if (game->rc.dir_x < 0)
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)] != '1' && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x - 0.5)] != '1')
            game->fpos_x += game->rc.dir_x * game->rc.move_speed;
    if (game->rc.dir_y >= 0)
        if(game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)] != '1' && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y += game->rc.dir_y * game->rc.move_speed;
    if (game->rc.dir_y < 0)
        if(game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)] != '1' && game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y += game->rc.dir_y * game->rc.move_speed;
}
static void    ft_go_back(t_game *game)
{
    if (game->rc.dir_x >= 0)
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)] != '1' && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x - 0.5)] != '1')
            game->fpos_x -= game->rc.dir_x * game->rc.move_speed;
    if (game->rc.dir_x < 0)
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)] != '1' && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x + 0.5)] != '1')
            game->fpos_x -= game->rc.dir_x * game->rc.move_speed;
    if (game->rc.dir_y >= 0)
        if(game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)] != '1' && game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y -= game->rc.dir_y * game->rc.move_speed;
    if (game->rc.dir_y < 0)
        if(game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)] != '1' && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y -= game->rc.dir_y * game->rc.move_speed;
}
static void    ft_go_left(t_game *game)   // we keep the debug with 'puts function' just in case we need to modify again
{
    if (game->rc.dir_x >= 0 && game->rc.dir_y < 0)
    {//puts("AAA");
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x - 0.5)] != '1')
            game->fpos_x += (game->rc.dir_x -1) * game->rc.move_speed;
    }
    if (game->rc.dir_y < 0 && game->rc.dir_x >= 0)
    {//puts("BBB");
        if(game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)] != '1'
            && game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y -= (game->rc.dir_y +1) * game->rc.move_speed;
    }
    if (game->rc.dir_x < 0 && game->rc.dir_y < 0)
    {//puts("CCC");
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x - 0.5)] != '1')
            game->fpos_x -= (game->rc.dir_x +1) * game->rc.move_speed;
    }
    if (game->rc.dir_y < 0 && game->rc.dir_x < 0)
    {//puts("DDD");
        if(game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y += (game->rc.dir_y +1) * game->rc.move_speed;
    }
    if (game->rc.dir_x < 0 && game->rc.dir_y >= 0)
    {//puts("EEE");
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x + 0.5)] != '1')
            game->fpos_x += (game->rc.dir_x +1) * game->rc.move_speed;
    }
    if (game->rc.dir_y >= 0 && game->rc.dir_x < 0)
    {//puts("FFF");
        if(game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y -= (game->rc.dir_y -1) * game->rc.move_speed;
    }
    if (game->rc.dir_x >= 0 && game->rc.dir_y >= 0)
    {//puts("GGG");
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x + 0.5)] != '1')
            game->fpos_x -= (game->rc.dir_x -1) * game->rc.move_speed;
    }
    if (game->rc.dir_y >= 0 && game->rc.dir_x >= 0)
    {//puts("HHH");
        if(game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)] != '1'
            && game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y += (game->rc.dir_y -1) * game->rc.move_speed;
    }
}
static void    ft_go_right(t_game *game)   // we keep the debug with 'puts function' just in case we need to modify again
{
    if (game->rc.dir_x >= 0 && game->rc.dir_y < 0)
    {//puts("AAA");
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x + 0.5)] != '1')
            game->fpos_x -= (game->rc.dir_x -1) * game->rc.move_speed;
    }
    if (game->rc.dir_y < 0 && game->rc.dir_x >= 0)
    {//puts("BBB");
        if(game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x - 0.4)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y += (game->rc.dir_y +1) * game->rc.move_speed;
    }
    if (game->rc.dir_x < 0 && game->rc.dir_y < 0)
    {//puts("CCC");
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x + 0.5)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x + 0.5)] != '1')
            game->fpos_x += (game->rc.dir_x +1) * game->rc.move_speed;
    }
    if (game->rc.dir_y < 0 && game->rc.dir_x < 0)
    {//puts("DDD");
        if(game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y -= (game->rc.dir_y +1) * game->rc.move_speed;
    }
    if (game->rc.dir_x < 0 && game->rc.dir_y >= 0)
    {//puts("EEE");
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x + 0.5)] != '1')
            game->fpos_x -= (game->rc.dir_x +1) * game->rc.move_speed; 
    }
    if (game->rc.dir_y >= 0 && game->rc.dir_x < 0)
    {//puts("FFF");
        if(game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y += (game->rc.dir_y -1) * game->rc.move_speed;
    }
    if (game->rc.dir_x >= 0 && game->rc.dir_y >= 0)
    {//puts("GGG");
        if(game->mapcpy[(int)(game->fpos_y - 0.4)][(int)(game->fpos_x - 0.5)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.4)][(int)(game->fpos_x + 0.5)] != '1')
            game->fpos_x += (game->rc.dir_x -1) * game->rc.move_speed;
    }
    if (game->rc.dir_y >= 0 && game->rc.dir_x >= 0)
    {//puts("HHH");
        if(game->mapcpy[(int)(game->fpos_y - 0.5)][(int)(game->fpos_x - 0.4)] != '1'
            && game->mapcpy[(int)(game->fpos_y + 0.5)][(int)(game->fpos_x + 0.4)] != '1')
            game->fpos_y -= (game->rc.dir_y -1) * game->rc.move_speed;
    }
}


void ft_player_moves(t_game *game)
{
	game->ppos_x = (game->fpos_x * 20);
	game->ppos_y = (game->fpos_y * 20);
    game->ipos_x = game->fpos_x;
	game->ipos_y = game->fpos_y;

    if (game->moves[0] == 'u')
        ft_go_straight(game);
    if (game->moves[3] == 'd')
        ft_go_back(game);
    if (game->moves[2] == 'r')
        ft_go_right(game);
    if (game->moves[1] == 'l')
        ft_go_left(game);
}

