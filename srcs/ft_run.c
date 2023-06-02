/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/06/02 10:45:13 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    ft_run(t_game *game)
{
    // ft_print_floor_ceiling(game);
    ft_camera(game);
    
    // printf("%f\n", game->mov.degrees);
   
    return (0);
}