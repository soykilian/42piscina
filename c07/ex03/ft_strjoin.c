/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:03:25 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/13 15:15:14 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_concatenate(char *p, char *pi, int index)
{
	int	i;

	i = 0;
	while (pi[i] != 0)
	{
		p[index + i] = pi[i];
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (str[j] != 0)
	{
		j++;
	}
	return (j);
}

void	ft_cat(char *p, int size, char **strs, char *sep)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < size)
	{
		c += ft_concatenate(p, strs[i], c);
		if (i != size - 1)
			c += ft_concatenate(p, sep, c);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*p;
	int		i;
	int		j;
	int		c;

	p = NULL;
	i = 0;
	j = 0;
	c = 0;
	if (size <= 0)
		return (p);
	while (i < size)
	{
		c += ft_strlen(strs[i]);
		i++;
	}
	c = 0;
	p = malloc(c + ((size - 1) * ft_strlen(sep)));
	i = 0;
	ft_cat(p, size, strs, sep);
	return (p);
}
