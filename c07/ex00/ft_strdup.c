/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:39:26 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/13 20:52:11 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

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
	p = malloc(len);
	i = 0;
	while (i <= len)
	{
		p[i] = src[i];
		i++;
	}
	return (p);
}
