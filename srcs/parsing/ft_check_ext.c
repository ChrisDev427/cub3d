/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:36:41 by chris             #+#    #+#             */
/*   Updated: 2023/07/15 23:26:24 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_ext(char *file)
{
	int	fd;

	fd = open(file, F_OK);
	if (fd < 0)
	{
		ft_printf("Error : wrong file\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (ft_strncmp(".cub", file + (ft_strlen(file) - 4), 4) != 0)
	{
		ft_printf("Error : extension error\n");
		exit(EXIT_FAILURE);
	}
}
