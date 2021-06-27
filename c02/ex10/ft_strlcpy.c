/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:19:01 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/27 16:55:44 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size || src[i] != 0)
		dest[i] = '\0';
	return (size);
}

/* int main (void)
{
	char *src;
	char *dest;
	char text1[] = "MAVI";
	char text2[] =  "P";

	src=text1;
	dest=text2;
	//strlcpy(dest, src, 6);
	int result = ft_strlcpy(dest,src,3);
	int i = 0;
	while (dest[i] != 0){
		printf("%c", dest[i]);
		//char act = dest[i];
		i++;
	}
} */