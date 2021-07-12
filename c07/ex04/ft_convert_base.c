/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:14:29 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/12 20:04:24 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

void	ft_swap(char *sol)
{
	int		i;
	int		l;
	int		end;
	char	aux;

	i = 0;
	l = 0;
	while (sol[l] != 0)
		l++;
	end = l / 2;
	i = 0;
	aux = 0;
	while (i < end)
	{
		aux = sol[i];
		sol[i] = sol[l - 1 - i];
		sol[l - 1 - i] = aux;
		i++;
	}
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
char	*ft_sign(char *res, int sign, int lres)
{
	char	*sol;
	int		i;
	
	i = 1;
	sol = malloc(lres + 1);
	if (sign == -1)
	{
		*sol = '-';
		while ( i < lres)
		{
			sol[i] = res[i - 1];
			i++;
		}
		return (sol);
	}
	return (res);
}

char 	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		ls_to;
	int		i;
	int		negative;
	char	res[32];
	int		ls;
	int		ls_from;
	int		dec;
	int		lres;

	i = 0;
	ls = 0;
	ls_from = 0;
	ls_to = 0;
	lres = 0;
	while (i < 32)
		res[i++] = 0;
	while (nbr[ls] != 0)
		ls++;
	if (!check_base(base_to) || !check_base(base_from))
		return (0);
	while (base_to[ls_to] != 0)
		ls_to++;
	while (base_from[ls_from++] != 0)
		ls_from ++;
	negative = ft_atoi(nbr, res, base_from);
	while (res[lres] != 0)
		lres++;
	dec = ft_x_10(res, base_from, ls_from, lres);
	return(ft_sign(ft_10_y(dec, base_to, ls_to, 0), negative, lres));
}

int main (void)
{
	printf("%s", ft_convert_base("---bbacd", "abcd","champino"));
}
