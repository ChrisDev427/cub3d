
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
    //perform DDA
    game->rc.hit = 0;
    while (game->rc.hit == 0)
    {
        //jump to next map square, either in x-direction, or in y-direction
        if (game->rc.side_dist_x < game->rc.side_dist_y)
        {
          game->rc.side_dist_x += game->rc.delta_dist_x;
          game->rc.map_x += game->rc.step_x;
          game->rc.side = 0;
        }
        else
        {
          game->rc.side_dist_y += game->rc.delta_dist_y;
          game->rc.map_y += game->rc.step_y;
          game->rc.side = 1;
        }
        if (game->mapcpy[game->rc.map_y][game->rc.map_x] == '1')
            game->rc.hit = 1;
    }
    // int size_line;
    // int endian;
    // int bits_per_pixel;
    // char *res;
	// res = mlx_get_data_addr(game->image.north.img, &bits_per_pixel,
	//  		&size_line, &endian);
    // printf("res =            [%s]\n", res);
    // printf("endian =         [%d]\n", endian);
    // printf("bpp =            [%d]\n", bits_per_pixel);
    // printf("sizeline =       [%d]\n", size_line);

	// game->rc.color = *(unsigned int*)res;

	// if (game->rc.map_x > game->ipos_x)
	// 	game->rc.color = WALLS_COLOR_2;
	// else
	// 	game->rc.color = 0x345622;
	// if (game->rc.side == 1)
	// {
	// 	if (game->rc.map_y > game->ipos_y)
	// 		game->rc.color = WALLS_COLOR_1;
	// 	else
	// 		game->rc.color = WALLS_COLOR_3;

	// }
}


void ft_raycasting(t_game *game)
{
	char **texture;

	texture = malloc(sizeof(char*) * (4 + 1));
  	for(int i = 0; i < 4; i++)
		texture[i] = malloc(sizeof(char) * (64 * 64 + 1));//.resize(texWidth * texHeight);
    game->rc.ray_x = 0;
    while (game->rc.ray_x < SCREEN_WIDTH)
    {
        ft_loop_init(game);
        ft_step_sidedist(game);
        ft_dda_algo(game);


//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
        if (game->rc.side == 0)
            game->rc.perp_wall_dist = (game->rc.side_dist_x - game->rc.delta_dist_x);
        else
            game->rc.perp_wall_dist = (game->rc.side_dist_y - game->rc.delta_dist_y);
        if (game->rc.ray_x == SCREEN_WIDTH /2)
            game->rc.ray_dist =  game->rc.perp_wall_dist * 20;
		game->needle_length = game->rc.perp_wall_dist * 20;
        if (game->needle_length > MP_WIDTH / 3)
            game->needle_length = MP_WIDTH / 3;
         ft_draw_axis(game, game->rc.ray_dir_x, game->rc.ray_dir_y, game->needle_length);
//Calculate height of line to draw on screen
        game->rc.line_height = (int)(SCREEN_HEIGHT / game->rc.perp_wall_dist);
//calculate lowest and highest pixel to fill in current stripe
        game->rc.draw_start = -game->rc.line_height / 2 + SCREEN_HEIGHT / 2;
        if(game->rc.draw_start < 0)
            game->rc.draw_start = 0;
        game->rc.draw_end = game->rc.line_height / 2 + SCREEN_HEIGHT / 2;
        if(game->rc.draw_end >= SCREEN_HEIGHT)
            game->rc.draw_end = SCREEN_HEIGHT - 1;

	// 	//texturing calculations
    //   int texNum = game->mapcpy[game->rc.map_y][game->rc.map_x] - 1; //1 subtracted from it so that texture 0 can be used!

    //   //calculate value of wallX
    //   double wallX; //where exactly the wall was hit
    //   if (game->rc.side == 0)
	//   	wallX = game->fpos_x + game->rc.perp_wall_dist * game->rc.ray_dir_y;
    //   else
	//   	wallX = game->fpos_x + game->rc.perp_wall_dist * game->rc.ray_dir_x;
    //   wallX -= floor((wallX));

    //   //x coordinate on the texture
    //   int texX = (int)(wallX * (double)game->rc.texwidth);
    //   if(game->rc.side == 0 && game->rc.ray_dir_x > 0)
	//   	texX = game->rc.texwidth - texX - 1;
    //   if(game->rc.side == 1 && game->rc.ray_dir_y < 0)
	//   	texX = game->rc.texwidth - texX - 1;
    	//printf("endian =         [%d]\n", game->image.north.endian);
    	//printf("bpp =            [%d]\n", game->image.north.bits_per_pixel);
    	//printf("sizeline =       [%d]\n", game->image.north.bits_per_pixel);
		//unsigned int pixel = img_data[game->rc.draw_start * (game->image.north.line_length / 4) + game->rc.ray_x / 64];
        //ft_vertical_draw(game, game->rc.draw_start, game->rc.draw_end, pixel);

    game->rc.ray_x++;
    }
}
