/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:40:44 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 18:41:52 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_char(int num)
{
	int		rest;
	char	ch_f;

	if (num < 10)
	{
		ch_f = num + 48;
		write(1, &ch_f, 1);
	}
	else
	{
		ft_init_char(num / 10);
		rest = (num % 10);
		ch_f = rest + 48;
		write(1, &ch_f, 1);
	}
}

void	imprimir (int x, int y)
{
	if (x == 0 || x < 10 )
	{
		write(1, "0", 1);
	}
	ft_init_char(x);
	write(1, " ", 1);
	if (y == 0 || y < 10)
	{
		write(1, "0", 1);
	}
	ft_init_char(y);
	write(1, ",", 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x != 99)
	{
		while (y != 99)
		{
			y++;
			if (x < y)
			{
				imprimir(x, y);
			}
		}
		x++;
		y = 00;
	}
}
