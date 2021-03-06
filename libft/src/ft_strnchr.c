/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:05:19 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 13:05:19 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strnchr(const char *s, char ch, int n)
{
	int		res;

	if (ch == '\0' || !s)
		return (-1);
	res = 0;
	while (*s)
	{
		if (*s == ch)
			n--;
		if (n == 0)
			return (res);
		res++;
		s++;
	}
	return (-1);
}
