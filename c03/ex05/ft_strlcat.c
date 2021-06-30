/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:40:56 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/30 16:56:19 by mclerico         ###   ########.fr       */
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

	i = 0;
	l = ft_len(dest);
	while (src[i] != 0 || i < (size - l - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (l - ft_len(src));
}

int main(void)
{
	char text1[5] = "hola\0";
	char text2[11]  = "mavictoria\0";
	int n;
	
	n = strlcat(text1, text2, 7);
	printf("%s", text1);
}