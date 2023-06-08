#include <mlx.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		center_x; // Position x du centre de rotation de l'aiguille
	int		center_y; // Position y du centre de rotation de l'aiguille
	int		rotation_angle; // Angle de rotation de l'aiguille
}				t_vars;

void	draw_axis(t_vars *vars)
{
	int	y;

	y = 0;
	while (y < 600) // Hauteur de la fenêtre
	{
		mlx_pixel_put(vars->mlx, vars->win, vars->center_x, y, 0xFFFFFF); // Dessine un pixel blanc à la position (center_x, y)
		y++;
	}
}

void	rotate_axis(t_vars *vars, int angle)
{
	double	radians = (double)angle * PI / 180.0;
	int		needle_length = 200; // Longueur de l'aiguille

	int		end_x = vars->center_x + (int)(needle_length * cos(radians));
	int		end_y = vars->center_y + (int)(needle_length * sin(radians));

	mlx_clear_window(vars->mlx, vars->win); // Efface la fenêtre
	draw_axis(vars); // Dessine l'axe fixe
	mlx_pixel_put(vars->mlx, vars->win, vars->center_x, vars->center_y, 0xFF0000); // Dessine le point de rotation en rouge
	mlx_pixel_put(vars->mlx, vars->win, end_x, end_y, 0x00FF00); // Dessine l'extrémité de l'aiguille en vert

	int	dx = end_x - vars->center_x;
	int	dy = end_y - vars->center_y;
	int	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float	x_increment = (float)dx / (float)steps;
	float	y_increment = (float)dy / (float)steps;

	float	x = vars->center_x;
	float	y = vars->center_y;

	for (int i = 0; i <= steps; i++)
	{
		x += x_increment;
		y += y_increment;
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
	}
}

int		key_press(int keycode, t_vars *vars)
{
	if (keycode == 123) // Touche flèche gauche
	{
		vars->rotation_angle -= 10; // Rotation de l'aiguille de 10 degrés dans le sens anti-horaire
	}
	else if (keycode == 124) // Touche flèche droite
	{
		vars->rotation_angle += 10; // Rotation de l'aiguille de 10 degrés dans le sens horaire
	}
	rotate_axis(vars, vars->rotation_angle); // Fait pivoter l'aiguille
	return (0);
}

int		main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Rotation Axe");
	vars.center_x = 400; // Position x du centre de rotation de l'aiguille
	vars.center_y = 300; // Position y du centre de rotation de l'aiguille
	vars.rotation_angle = 0; // Angle de rotation initial de l'aiguille
	draw_axis(&vars); // Dessine l'axe initial
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
