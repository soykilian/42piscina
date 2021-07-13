/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:37:43 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/13 15:08:08 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *dest, char *src, int size)
{
	int		i;
	char	font;

	i = 0;
	dest = malloc(size);
	while (src[i] != '\0')
	{
		font = src[i];
		dest[i] = font;
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	unsigned int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str			*s;
	int					i;

	s = malloc(sizeof(t_stock_str));
	if (!s)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strcpy(s[i].copy, av[i], s[i].size);
		i++;
	}
	s[i].str = 0;
	return (s);
}
