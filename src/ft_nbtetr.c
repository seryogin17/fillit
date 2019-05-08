/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbtetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:31:06 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:31:06 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nbtetr(char *file)
{
	int		fd;
	int		cnt;
	char	*line;

	cnt = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		cnt++;
		ft_strdel(&line);
	}
	return (cnt / 5 + 1);
	close(fd);
}
