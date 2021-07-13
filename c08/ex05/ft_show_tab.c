/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:01:27 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/12 23:16:22 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *dest, char *src, int size)
{
	int		i;
	char	font;

	i = 0;
	dest = malloc(size);
	while (src[i] != '\0')
	{
		font = src[i];
		dest[i] = font;
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	unsigned int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str			*s;
	int					i;

	s = malloc(sizeof(t_stock_str));
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strcpy(s[i].copy, av[i], s[i].size);
		i++;
	}
	s[i].str = 0;
	return (s);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	int	n;

	n = nbr;
	if (n >= 10 )
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
	else
		ft_putchar(n + '0');
}

void ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, par[i].size);	
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, par[i].size);
		write(1, "\n", 1);
		i++;
	}
}
int main(void)
{
	char	**p;

	p = malloc(8 * 3);
	p[0] = "hola";
	p[1] = "mundo";
	p[2] = "pepe";
	ft_show_tab(ft_strs_to_tab(3, p));
}
