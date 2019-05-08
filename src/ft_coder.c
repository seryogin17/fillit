/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:30:15 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:30:15 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_tetr(char *file)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*tetr;
	char	*full;

	fd = open(file, O_RDONLY);
	tetr = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		temp = tetr;
		full = ft_strjoin(line, "\n");
		tetr = ft_strjoin(temp, full);
		ft_strdel(&temp);
		ft_strdel(&full);
		ft_strdel(&line);
	}
	return (tetr);
}

int		*ft_coder(char *tetr, int n)
{
	int		*code;
	int		i;
	int		cnt;
	int		cut;

	i = 0;
	cnt = 0;
	cut = 0;
	if (!(code = (int *)malloc(sizeof(int) * (3 * n + 1))))
		return (NULL);
	while (tetr[i])
	{
		if (tetr[i] == '#')
		{
			if (cnt++ % 4)
				*code++ = i - cut;
			cut = i;
		}
		i++;
	}
	*code = 0;
	ft_strdel(&tetr);
	return (code - 3 * n);
}

void	ft_reverse(int *code)
{
	int		i;

	i = 0;
	while (code[i])
	{
		if (code[i] != 1)
			code[i]--;
		i++;
	}
}

int		*ft_code(char *file, int n, size_t size)
{
	int		*code;
	int		remainder;

	remainder = size - 4;
	code = ft_coder(ft_tetr(file), n);
	if (remainder > 0)
		while (remainder-- > 0)
			ft_cupdate(code);
	else
		while (remainder++ < 0)
			ft_reverse(code);
	return (code);
}
