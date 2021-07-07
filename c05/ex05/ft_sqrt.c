/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:39:46 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/07 15:58:17 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_sqrt(int nb)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (i * i <= nb)
	{
		n = i * i;
		if (n == nb)
			return (i);
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%d", ft_sqrt(2147395600));
	return (0);
}
