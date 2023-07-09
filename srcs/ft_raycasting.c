
#include "cub3d.h"

static void ft_loop_init(t_game *game)
{
    game->rc.map_x = (int)game->fpos_x;
    game->rc.map_y = (int)game->fpos_y;
    game->rc.camera_x = 2 * game->rc.ray_x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space
    game->rc.ray_dir_x = game->rc.dir_x - game->rc.plane_x * game->rc.camera_x;
    game->rc.ray_dir_y = game->rc.dir_y - game->rc.plane_y * game->rc.camera_x;
    if (game->rc.ray_dir_x == 0)
        game->rc.delta_dist_x = __DBL_MAX__;
    else
        game->rc.delta_dist_x = fabs(1 / game->rc.ray_dir_x);
    if (game->rc.ray_dir_y == 0)
        game->rc.delta_dist_y = __DBL_MAX__;
    else
        game->rc.delta_dist_y = fabs(1 / game->rc.ray_dir_y);
}
static void ft_step_sidedist(t_game *game)
{
    //calculate step and initial sideDist
    if (game->rc.ray_dir_x < 0)
    {
        game->rc.step_x = -1;
        game->rc.side_dist_x = (game->fpos_x - game->rc.map_x) * game->rc.delta_dist_x;
    }
    else
    {
        game->rc.step_x = 1;
        game->rc.side_dist_x = (game->rc.map_x + 1.0 - game->fpos_x) * game->rc.delta_dist_x;
    }
    if (game->rc.ray_dir_y < 0)
    {
        game->rc.step_y = -1;
        game->rc.side_dist_y = (game->fpos_y - game->rc.map_y) * game->rc.delta_dist_y;
    }
    else
    {
        game->rc.step_y = 1;
        game->rc.side_dist_y = (game->rc.map_y + 1.0 - game->fpos_y) * game->rc.delta_dist_y;
    }
}

static void ft_dda_algo(t_game *game)
{
    game->rc.hit = 0;
    while (game->rc.hit == 0)
    {
        if (game->rc.side_dist_x < game->rc.side_dist_y)
        {
            game->rc.side_dist_x += game->rc.delta_dist_x;
            game->rc.map_x += game->rc.step_x;
            if (game->rc.map_x > game->ipos_x)
                game->rc.side = 0;
            else
                game->rc.side = 3;
        }
        else
        {
            game->rc.side_dist_y += game->rc.delta_dist_y;
            game->rc.map_y += game->rc.step_y;
            if (game->rc.map_y > game->ipos_y)
                game->rc.side = 2;
            else
                game->rc.side = 1;
        }
        if (game->mapcpy[game->rc.map_y][game->rc.map_x] == '1')
            game->rc.hit = 1;
    }
    if (game->rc.side == 0)
	    game->rc.color = WALLS_WEST;
	else if (game->rc.side == 1)
		game->rc.color = WALLS_NORTH;
    else if (game->rc.side == 3)
		game->rc.color = WALLS_EAST;
    else if (game->rc.side == 2)
		game->rc.color = WALLS_SOUTH;
}

void ft_raycasting(t_game *game)
{
    game->rc.ray_x = 0;
    while (game->rc.ray_x < SCREEN_WIDTH)
    {
        ft_loop_init(game);
        ft_step_sidedist(game);
        ft_dda_algo(game);
//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
        if (game->rc.side == 0 || game->rc.side == 3)
            game->rc.perp_wall_dist = (game->rc.side_dist_x - game->rc.delta_dist_x);
        else if (game->rc.side == 2 || game->rc.side == 1)
            game->rc.perp_wall_dist = (game->rc.side_dist_y - game->rc.delta_dist_y);
        if (game->rc.ray_x == SCREEN_WIDTH /2)
            game->rc.ray_dist =  game->rc.perp_wall_dist * 20;
//Calculate height of line to draw on screen
        game->rc.line_height = (int)(SCREEN_HEIGHT / game->rc.perp_wall_dist);
//calculate lowest and highest pixel to fill in current stripe
        game->rc.draw_start = -game->rc.line_height / 2 + SCREEN_HEIGHT / 2;
        if(game->rc.draw_start < 0)
            game->rc.draw_start = 0;
        game->rc.draw_end = game->rc.line_height / 2 + SCREEN_HEIGHT / 2;
        if(game->rc.draw_end >= SCREEN_HEIGHT)
            game->rc.draw_end = SCREEN_HEIGHT - 1;
        ft_vertical_draw(game, game->rc.draw_start, game->rc.draw_end, game->rc.color);
    game->rc.ray_x++;
    }
}
