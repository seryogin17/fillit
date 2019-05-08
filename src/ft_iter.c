/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:30:37 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:30:37 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_search(char *map, int nb)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'A' + (nb - 1))
			break ;
		i++;
	}
	return (i);
}

void		ft_delete(char *map, int nb)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'A' + (nb - 1))
			map[i] = '.';
		i++;
	}
}

int			ft_cut(char *pseudomap, int nb)
{
	int cut;

	cut = ft_search(pseudomap, nb);
	ft_delete(pseudomap, nb);
	return (cut);
}

t_update	ft_backtrack(int *pseudocode, char *pseudomap, int n)
{
	int			nb;
	int			cut;
	t_update	pseudo;

	nb = ft_nblock(pseudocode, n);
	cut = ft_cut(pseudomap, nb);
	while (!ft_fill(pseudocode - 3, pseudomap + cut + 1, n))
	{
		if (nb-- > 0)
			pseudocode -= 3;
		if (nb > 0)
			cut = ft_cut(pseudomap, nb);
		else
		{
			pseudomap = ft_mupdate(pseudocode, pseudomap);
			break ;
		}
	}
	pseudo.map = pseudomap;
	pseudo.code = pseudocode;
	return (pseudo);
}

void		ft_iter(int *code, char *map, int n)
{
	void		*tmp;
	t_update	set;

	tmp = (void *)code;
	while (42)
	{
		while (*code && ft_fill(code, map, n))
			code += 3;
		if (!*code)
		{
			ft_putstr(map);
			ft_strdel(&map);
			ft_memdel(&tmp);
			return ;
		}
		set = ft_backtrack(code, map, n);
		code = set.code;
		map = set.map;
	}
}
