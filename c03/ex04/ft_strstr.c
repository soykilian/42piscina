/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:18:53 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/05 13:35:28 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int		c;

	c = 0;
	while (*str != 0)
	{
		c++;
		str++;
	}
	return (c);
}

int	check_possible_needle(char *p, char *needle)
{
	int	f_size;
	int	j;

	j = 0;
	f_size = 0;
	while (*p == needle[j] && needle[j] && *p)
	{
		f_size++;
		j++;
		p++;
	}
	return (f_size);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	size;

	size = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return (str);
	while (*str != 0)
	{
		if (*str == to_find[0])
		{
			if (check_possible_needle(str, to_find) == size)
				return (str);
		}
		str++;
	}
	return (0);
}
