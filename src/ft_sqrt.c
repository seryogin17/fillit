/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:31:10 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 16:31:10 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int		root;

	root = 11;
	while (n != root * root && root != 0)
		root--;
	if (!root)
		return (ft_sqrt(n + 1));
	return (root);
}
