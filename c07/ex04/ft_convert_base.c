/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:14:29 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/14 21:00:07 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		check_base(char *base);
int		check_is_base(char str, char *base);
void	ft_swap(char *sol);
char	*ft_sign(char *res, int sign, int lres);

int	ft_atoi(char *str, char *res, char *base)
{
	int		i;
	int		j;
	int		cont;

	i = 0;
	j = 0;
	cont = 0;
	while (((str[i] > 8 && str[i] < 14) || str[i] == 32))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			cont++;
		i++;
	}
	while (check_is_base(str[i], base))
	{
		res[j++] = str[i];
		i++;
	}
	if (cont % 2 != 0)
		return (-1);
	return (1);
}

int	ft_x_10(char *res, char *base, int lenbase, int lres)
{
	int		a;
	int		i;	
	int		j;
	int		pow;
	int		sol;

	i = lres;
	j = -1;
	sol = 0;
	while (--i >= 0)
	{
		while (base[++j] != 0)
		{
			if (base[j] == res[i])
			{
				pow = lres - i;
				a = j;
				while (--pow > 0)
					a *= lenbase;
				sol += a;
			}
		}
		j = 0;
	}
	return (sol);
}

char	*ft_10_y(int n, char *base, int l, int j)
{
	int			t;
	char		*sol;

	t = 0;
	sol = malloc(32);
	if (n < l)
		sol[j] = base[n];
	else
	{
		t = n % l;
		sol = ft_10_y(n / l, base, l, j + 1);
		sol[j] = base[t];
	}
	ft_swap(sol);
	return (sol);
}

char 	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		l[3];
	int		i;
	int		negative;
	char	res[32];
	int		dec;

	i = 0;
	l[0] = 0;
	l[1] = 0;
	l[2] = 0;
	while (i < 32)
		res[i++] = 0;
	if (!check_base(base_to) || !check_base(base_from))
		return (0);
	while (base_to[l[0]] != 0)
		l[0]++;
	while (base_from[l[1]++] != 0)
		l[1]++;
	negative = ft_atoi(nbr, res, base_from);
	while (res[l[2]] != 0)
		l[2]++;
	dec = ft_x_10(res, base_from, l[1], l[2]);
	return (ft_sign(ft_10_y(dec, base_to, l[0], 0), negative, l[2]));
}
