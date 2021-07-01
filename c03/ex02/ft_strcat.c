/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:11:46 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/30 15:06:39y mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (dest[j] != 0)
	{
		j++;
	}
	while (src[i] != 0)
	{
		c = src[i++];
		dest[j++] = c;
	}
	dest[j] = '\0';
	return (dest);
}
