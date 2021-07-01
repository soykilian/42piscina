/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:40:56 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 17:13:09 by mclerico         ###   ########.fr       */
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

void	ft_cat(char *dest, char *src, unsigned int size)
{
	unsigned int	l;
	unsigned int	i;

	l = ft_len(dest);
	i = 0;
	while (i < size)
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i] = 0;
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l;
	unsigned int	ls;

	ls = ft_len(src);
	l = ft_len(dest);
	if (size <= l)
		return (ls + l);
	if (ls + l + 1 > size)
		ft_cat(dest, src, size - l - 1);
	else if (size > l + 1)
		ft_cat(dest, src, ls);
	return (l + ls);
}

int main(void)
{
	char text1[] = "hola\0";
	char text2[20]  = "mavict";
	
	//strlcat(text2, text1, 4);
	ft_strlcat(text2, text1, 8);
	printf("%s \n", text2);
	printf("%d", text2[7]);
}
