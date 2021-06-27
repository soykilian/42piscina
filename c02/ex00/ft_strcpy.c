/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:18:22 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/27 13:13:23 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strcpy(char *dest, char *src)
{
	int		i;
	char	font;

	i = 0;
	while (src[i] != '\0')
	{
		font = src[i];
		dest[i] = font;
		printf("%c", dest[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
