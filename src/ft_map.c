/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:30:42 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:30:42 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_map(size_t size)
{
	char	*map;
	size_t	len;
	size_t	i;
	size_t	tmp;

	len = (size + 1) * size;
	if (!(map = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	tmp = size;
	while (i < len)
	{
		if (tmp--)
			map[i++] = '.';
		else
		{
			map[i++] = '\n';
			tmp = size;
		}
	}
	map[i] = '\0';
	return (map);
}
