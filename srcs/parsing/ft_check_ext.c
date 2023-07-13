/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:36:41 by chris             #+#    #+#             */
/*   Updated: 2023/07/13 10:05:35 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_ext(char *file)
{
	if (ft_strrchr(file, '/'))
		file = &file[ft_str_rchr(file, '/')];
	if (ft_strcmp(".cub", ft_strrchr(file, '.')) != 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
}


