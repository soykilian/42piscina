/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:37:43 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/14 11:23:28 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_sizeof(char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*p;
	int		i;

	len = ft_sizeof(src);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = src[i];
	return (p);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str			*s;
	int					i;

	s = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_sizeof(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strdup(av[i]);
		i++;
	}
	s[i].str = 0;
	return (s);
}
