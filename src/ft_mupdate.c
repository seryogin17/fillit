/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:30:53 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:30:53 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_cupdate(int *code)
{
	int		i;

	i = 0;
	while (code[i])
	{
		if (code[i] != 1)
			code[i]++;
		i++;
	}
}

char	*ft_mupdate(int *code, char *map)
{
	int		size;

	ft_cupdate(code);
	size = 0;
	while (map[size] != '\n')
		size++;
	ft_strdel(&map);
	return (ft_map(size + 1));
}
