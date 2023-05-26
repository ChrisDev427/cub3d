/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:36:41 by chris             #+#    #+#             */
/*   Updated: 2023/05/26 11:25:42 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_ext(char *file)
{
	if (!ft_found_char(file, '.'))
		return (0);
	if (ft_strcmp(".cub", ft_strrchr(file, '.')) != 0)
		return (0);
	return (1);
}

void	ft_open(char *file, int *fd)
{
	if (!ft_check_ext(file))
	{
		ft_putstr_fd("map file must be '.cub' !\n", 2);
		exit(EXIT_FAILURE);
	}
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
}
