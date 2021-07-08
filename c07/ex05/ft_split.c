/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:28:37 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/08 20:36:31 by mclerico         ###   ########.fr       */
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

void	ft_copy(int cl, char *charset, char **p, char *str)
{
	int		i;
	int		j;
	int		k;
	int		fletter;
	int		n;

	n = 0;
	i = 0;
	fletter = -1;
	j = 0;
	k = 0;
	while (str[i] != 0)
	{
		n = n_substr(str, charset, i);
		if (fletter == -1 && n == 0)
			fletter = i;
		else if (n > 0 || str[i + 1] == 0)
		{
			p[k] = malloc(i - fletter);
			while (fletter != i)
				p[k][j++] = str[fletter++];
			k++;
			fletter = -1;
			i += n * cl - 1;
			j = 0;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**p;
	int		i;
	int		fletter;
	int		n;
	int		cl;

	p = NULL;
	i = 0;
	n = 0;
	cl = 0;
	fletter = -1;
	while (charset[cl] != 0)
		cl++;
	while (str[i] != 0)
	{
		if (str[i] == charset[0])
		{
			i += (n_substr(str, charset, i) * cl);
			n++;
		}
		i++;
	}
	p = malloc(n * 8);
	ft_copy(cl, charset, p, str);
	return (p);
}

int	main(void)
{
	printf("%s\n", ft_split("hola--mundo--pepe", "--")[0]);
	printf("%s\n", ft_split("hola--mundo--pepe", "--")[1]);
	printf("%s\n", ft_split("hola--mundo--pepe", "--")[2]);
	return (0);
}
