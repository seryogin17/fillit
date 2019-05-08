/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:30:20 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:30:20 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fchecker(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) && i <= 129)
	{
		if ((i % 5 != 0 && ft_strlen(line) == 4) || \
				(i % 5 == 0 && !ft_strlen(line)))
		{
			i++;
			ft_strdel(&line);
			continue ;
		}
		else
		{
			ft_strdel(&line);
			return (1);
		}
	}
	if (i % 5 != 0 || i > 129)
		return (1);
	close(fd);
	return (0);
}
