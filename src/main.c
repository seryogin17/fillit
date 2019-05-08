/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:34:05 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:34:05 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		n;
	int		size;
	int		*code;
	char	*map;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	close(fd);
	if (ft_fchecker(av[1]) || ft_mchecker(av[1]))
	{
		ft_putstr("error\n");
		return (0);
	}
	n = ft_nbtetr(av[1]);
	size = ft_sqrt(4 * n);
	code = ft_code(av[1], n, size);
	map = ft_map(size);
	ft_iter(code, map, n);
	return (0);
}
