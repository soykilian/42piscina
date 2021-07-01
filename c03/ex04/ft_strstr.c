/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:18:53 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 13:42:54 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	length(char *str)
{
	int		length;
	int		j;

	j = 0;
	length = 0;
	while (str[j] != '\0')
		j++;
	length = j;
	return (length);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*index;
	int		l;

	i = 0;
	j = 0;
	index = str;
	l = length(to_find);
	while (str[i] != '\0' || (length(str) - i) >= length(to_find))
	{
		if (str[i] == to_find[j])
		{
			if (j == 0)
				index += i - 1;
			j++;
			i++;
		}
		else
		{
			j = 0;
			i++;
		}
		if (j == l)
			return (index);
	}
	return (str + i);
}

int main(void){
	char a[]= "Mariavivictoria";
	char b[]= "vic";
	char *c = ft_strstr(a, b);
	printf("%s", c);
}