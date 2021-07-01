/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 22:17:57 by mariavictor       #+#    #+#             */
/*   Updated: 2021/06/30 19:54:24 by mclerico         ###   ########.fr       */
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
