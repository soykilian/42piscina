/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:19:01 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 15:53:12 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_len(char *str)
{
	int		j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

char	*ft_copy(char *src, char *dest, unsigned int size)
{
	unsigned int	i;
	char			*s;
	char			*d;

	s = src;
	d = dest;
	i = 0;
	while (i++ < size)
	{
		*d++ = *s++;
	}	
	return (d);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	l;

	l = ft_len(src);
	if (l + 1 < size)
		ft_copy(src, dest, l + 1);
	else if (size != 0)
	{
		ft_copy(src, dest, size - 1);
		dest[size - 1] = 0;
	}
	return (l);
}
