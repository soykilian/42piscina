/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:59:07 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/05 11:05:15 by mclerico         ###   ########.fr       */
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
		{
			a = (a + (str[i] - 48)) * 10;
			if (str[i + 1] < 48 || str[i + 1] > 57)
				break ;
		}
		i++;
	}
	if (cont % 2 != 0)
		a = a * -1;
	return (a / 10);
}

int	main(void)
{
//	char text[18] = "   ---+--+1234ab56";
	printf("%i", ft_atoi("   ---+--+1234ab56"));
	return (0);
}
