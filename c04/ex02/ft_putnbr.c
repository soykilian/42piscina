/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:57:21 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/13 20:22:40 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	unsigned int	n;

	if (nbr < 0)
	{
		ft_putchar('-');
		n = (unsigned int) nbr * -1;
	}
	else
		n = (unsigned int) nbr;
	if (n >= 10 )
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
	else
		ft_putchar(n + '0');
}
