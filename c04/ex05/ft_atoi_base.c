/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:14:29 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/12 16:08:29 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_base(char *base)
{
	int	l;
	int	i;
	int	j;

	i = 0;
	j = 0;
	l = 0;
	while (base[i++] != 0)
		l++;
	i = -1;
	if (l < 2)
		return (0);
	while (i++ < l - 1)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != 0)
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		j = 0;
	}
	return (1);
}

int	check_is_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (str == base[i])
			return (1);
		i++;
	}
	return (0);
}

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

int	ft_num(char *res, char *base, int lenbase, int lres)
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

int	ft_atoi_base(char *str, char *base)
{
	int		lbase;
	int		i;
	int		negative;
	char	res[32];
	int		ls;

	i = 0;
	lbase = 0;
	ls = 0;
	while (str[ls] != 0)
		ls++;
	if (!check_base(base))
		return (0);
	while (base[i++] != 0)
		lbase++;
	i = 0;
	negative = ft_atoi(str, res, base);
	return (ft_num(res, base, lbase, ls) * negative);
}
