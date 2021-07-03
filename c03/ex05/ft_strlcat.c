/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:40:56 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/03 15:49:15 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_len(char *str)
{
	unsigned int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	ls;
	unsigned int	sol;

	ls = ft_len(src);
	l = ft_len(dest);
	sol = 0;
	i = 0;
	if (size <= l)
		sol = size + ls;
	else
		sol = l + ls;
	while (src[i] != 0 && l + 1 < size)
	{
		dest[l + i] = src[i];
		i += 1;
	}
	return (sol);
}
