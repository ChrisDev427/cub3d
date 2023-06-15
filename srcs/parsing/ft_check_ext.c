/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:36:41 by chris             #+#    #+#             */
/*   Updated: 2023/06/13 15:26:10 by axfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_check_dot_nb(char *file)
{
	int	i;
	int	dot_nb;

	i = 0;
	dot_nb = 0;
	while (file[i])
	{
		if (file[i] == '.')
			dot_nb++;
		i++;
	}
	if (dot_nb > 1)
	{
		ft_putstr_fd("error: extension map must be '.cub'\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_ext(char *file)
{
	if (ft_strrchr(file, '/'))
		file = &file[ft_str_rchr(file, '/')];
	ft_check_dot_nb(file);
	if (ft_strcmp(".cub", ft_strrchr(file, '.')) != 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
}


