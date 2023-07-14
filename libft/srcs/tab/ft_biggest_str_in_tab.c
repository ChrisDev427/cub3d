/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_str_in_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:13:41 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 17:54:43 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_biggest_str_in_tab(char **tab)
{
	int	y;
	int	x;
	int	biggest_str;

	y = 0;
	x = 0;
	biggest_str = 0;
	while (tab[y])
	{
		while (tab[y][x])
			x++;
		if (x > biggest_str)
			biggest_str = x;
		x = 0;
		y++;
	}
	return (biggest_str);
}
