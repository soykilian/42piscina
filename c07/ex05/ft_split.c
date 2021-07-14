/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:28:37 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/14 21:00:39 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	n_substr(char *str, char *charset, int index)
{
	int	l;
	int	i;
	int	ones;

	l = 0;
	i = 0;
	ones = 0;
	while (charset[l] != 0)
		l++;
	while (str[index + i] == charset[i])
	{
		i++;
		if (i == l)
		{
			return (n_substr(str, charset, index + i) + 1);
		}
	}
	return (0);
}

void	copiame_esta(int count[4], int n, char **p, char *str)
{
	int	j;

	j = 0;
	if (n == 0 && count[0] + 1 == count[3])
		count[0]++;
	p[count[2]] = malloc(count[0] - count[1]);
	while (count[0] != count[1])
		p[count[2]][j++] = str[count[1]++];
	count[2]++;
	count[1] = -1;
}

void	ft_copy(int cl, char *charset, char **p, char *str)
{
	int		c[4];
	int		n;

	c[3] = 0;
	while (str[c[3]] != '\0')
		c[3]++;
	c[0] = 0;
	c[1] = -1;
	c[2] = 0;
	n = 0;
	while (str[c[0]] != 0)
	{
		n = n_substr(str, charset, c[0]);
		if (c[1] == -1 && n == 0)
			c[1] = c[0];
		else if (((n > 0) || (n == 0 && c[0] + 1 == c[3])) && c[1] != -1)
		{
			copiame_esta(c, n, p, str);
			if (!(n == 0))
				c[0] += n * cl - 1;
		}
		else if (n != 0 && c[1] == -1)
			c[0] += n * cl - 1;
		c[0]++;
	}
}

int	count_words(char *str, char *charset, int cl, int size)
{
	int	n;
	int	i;
	int	c;
	int	fletter;

	i = 0;
	n = 0;
	c = 0;
	fletter = -1;
	while (str[i] != 0)
	{
		c = n_substr(str, charset, i);
		if (fletter == -1 && c == 0)
			fletter = 0;
		else if (c != 0 && fletter == 0)
		{
			i += (n_substr(str, charset, i) * cl);
			fletter = -1;
			n++;
		}
		else if (i + 1 == size && !n_substr(str, charset, i - cl + 1))
			n++;
		i++;
	}
	return (n);
}

char	**ft_split(char *str, char *charset)
{
	char	**p;
	int		i;
	int		c;
	int		n;
	int		cl;

	p = NULL;
	i = 0;
	n = 0;
	cl = 0;
	c = 0;
	while (str[c] != '\0')
		c++;
	while (charset[cl] != 0)
		cl++;
	n = count_words(str, charset, cl, c);
	p = malloc(n * 8);
	ft_copy(cl, charset, p, str);
	return (p);
}
