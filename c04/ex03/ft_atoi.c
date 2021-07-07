/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:59:07 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/06 17:16:50 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int	ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		cont;
	int		a;

	i = 0;
	cont = 0;
	a = 0;
	while (str[i] != 0)
	{
		if (str[i] == 45 && a == 0)
			cont++;
		else if (str[i] > 47 && str[i] < 58)
			a = (a * 10 + (str[i] - 48));
		else if (ft_isspace(str[i]) && a == 0)
		{
			i++;
			continue ;
		}
		else if (str[i] != '+')
			break ;
		i++;
	}
	if (cont % 2 != 0)
		a = a * -1;
	return (a);
}

int main (void)
{
	printf("con ft_atoi :%d ", ft_atoi("-2147483648"));
	printf(" con atoi :%d ", atoi("-1325632167"));
}

