/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:17:06 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/13 15:17:22 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_sign(char *res, int sign, int lres)
{
	char	*sol;
	int		i;

	i = 1;
	sol = malloc(lres + 1);
	if (sign == -1)
	{
		*sol = '-';
		while (i < lres)
		{
			sol[i] = res[i - 1];
			i++;
		}
		return (sol);
	}
	return (res);
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
