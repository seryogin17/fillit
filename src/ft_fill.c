/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:30:28 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:30:28 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill(int *code, char *map, int n)
{
	int		nb;
	int		i;

	nb = ft_nblock(code, n);
	i = 0;
	while (map[i])
	{
		if (map[i] == '.' \
	&& (int)ft_strlen(&map[i]) > *(code) + *(code + 1) + *(code + 2) \
	&& map[i + *(code)] == '.' \
	&& map[i + *(code) + *(code + 1)] == '.' \
	&& map[i + *(code) + *(code + 1) + *(code + 2)] == '.')
		{
			map[i] = 'A' + nb;
			map[i + *(code)] = 'A' + nb;
			map[i + *(code) + *(code + 1)] = 'A' + nb;
			map[i + *(code) + *(code + 1) + *(code + 2)] = 'A' + nb;
			return (1);
		}
		i++;
	}
	return (0);
}
