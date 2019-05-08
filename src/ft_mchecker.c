/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:30:48 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:30:48 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_neighbcount(char t[6][6], int i, int j)
{
	int		n;

	n = 0;
	if (t[i - 1][j] == '#')
		n++;
	if (t[i + 1][j] == '#')
		n++;
	if (t[i][j - 1] == '#')
		n++;
	if (t[i][j + 1] == '#')
		n++;
	return (n);
}

int		ft_neighbtotal(char t[6][6])
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 1;
	while (t[i][1])
	{
		j = 1;
		while (t[i][j])
		{
			if (t[i][j] == '#')
				n += ft_neighbcount(t, i, j);
			j++;
		}
		i++;
	}
	if (n != 6 && n != 8)
		return (1);
	return (0);
}

int		ft_grandchecker(char t[6][6])
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 1;
	while (t[i][1])
	{
		j = 1;
		while (t[i][j])
		{
			if (t[i][j] != '.' && t[i][j] != '#')
				return (1);
			if (t[i][j] == '#')
				c++;
			j++;
		}
		i++;
	}
	if (c != 4)
		return (1);
	return (ft_neighbtotal(t));
}

int		ft_recorder(int fd, char *line, char t[6][6])
{
	int		i;
	int		k;

	i = 1;
	while (get_next_line(fd, &line))
	{
		if (i < 5)
		{
			k = 0;
			while (line[k++])
				t[i][k] = line[k - 1];
			ft_strdel(&line);
			i++;
			if (i != 5)
				continue ;
		}
		get_next_line(fd, &line);
		ft_strdel(&line);
		if (!ft_grandchecker(t))
			i = 1;
		else
			return (1);
	}
	return (0);
}

int		ft_mchecker(char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	t[6][6];
	int		res;

	line = NULL;
	fd = open(file, O_RDONLY);
	i = 4;
	while (i >= 1)
	{
		t[0][i] = '\0';
		t[5][i] = '\0';
		t[i][0] = '\0';
		t[i][5] = '\0';
		i--;
	}
	res = ft_recorder(fd, line, t);
	close(fd);
	return (res);
}
