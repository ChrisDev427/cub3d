/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:43:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/07/13 17:55:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_strs(char **src, char **dst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		dst[i][j] = '\0';
		i++;
		j = 0;
	}
	dst[i] = 0;
}

char	**ft_strtab_dup(char **tab)
{
	char	**tabcpy;
	int		i;

	i = 0;
	tabcpy = malloc(sizeof(char *) * (ft_strtab_size(tab) + 1));
	if (!tabcpy)
		return (NULL);
	while (tab[i])
	{
		tabcpy[i] = malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		if (!tabcpy)
			return (NULL);
		i++;
	}
	fill_strs(tab, tabcpy);
	return (tabcpy);
}
