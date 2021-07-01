/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:59:07 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 21:06:00 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
			a = (a + (str[i] - 48)) * 10;
		i++;
	}
	if (cont % 2 != 0)
		a = a * -1;
	return (a/10);
}

int	main(void)
{
	printf("%i", atoi("   ---+--+1234ab56"));
	return (0);
}


