/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:20:59 by axfernan          #+#    #+#             */
/*   Updated: 2023/06/12 10:24:45 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define TILE_SIZE 20
#define WINDOW_WIDTH (MAP_WIDTH * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_HEIGHT * TILE_SIZE)

void draw_tile(void *mlx, void *win, int x, int y, int color) {
    int x_start = x * TILE_SIZE;
    int y_start = y * TILE_SIZE;
    int x_end = x_start + TILE_SIZE;
    int y_end = y_start + TILE_SIZE;

    for (int i = x_start; i < x_end; i++) {
        for (int j = y_start; j < y_end; j++) {
            mlx_pixel_put(mlx, win, i, j, color);
        }
    }
}

void draw_minimap(void *mlx, void *win, char *map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            char tile = map[y * MAP_WIDTH + x];

            if (tile == '1') {
                draw_tile(mlx, win, x, y, 0xFFFFFF); // Mur en blanc
            } else if (tile == 'E') {
                draw_tile(mlx, win, x, y, 0xFF0000); // Point d'entrée en rouge
            } else {
                draw_tile(mlx, win, x, y, 0x000000); // Autres cases en noir
            }
        }
    }
}

int main(void) {
    char map[] = "11111111111111111111"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000010000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "1000000000E0000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "100000000000000000001"
                 "111111111111111111111";

    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Minimap");

    draw_minimap(mlx, win, map);

    mlx_loop(mlx);

    return 0;
}
