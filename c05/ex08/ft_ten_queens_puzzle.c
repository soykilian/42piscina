/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:13:51 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/12 13:24:12 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int	is_valid(int x, int y, char *p)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	p[x] = y + 48;
	if (x == 0)
		return (1);
	while (i < x)
	{
		n = p[i] - 48;
		if (n != y && ((y - n) * (y - n) != (x - i) * (x - i)))
			i++;
		else
		{
			p[x] = 0;
			return (0);
		}
	}
	p[x] = 0;
	return (1);
}

int	solve_puzzle(char p[10], int x, int y)
{
	while (y <= 9)
	{
		if (is_valid(x, y, p))
		{
			p[x] = y + 48;
			if (x == 9)
			{
				write(1, p, 10);
				write(1, "\n", 1);
				p[x] = 0;
				return (0);
			}
			if (solve_puzzle(p, x + 1, 0))
				return (1);
			p[x] = 0;
		}
		y++;
	}	
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	char	p[10];
	int		x;
	int		y;
	int		cont;

	x = 0;
	y = 0;
	cont = 724;
	solve_puzzle(p, x, y);
	return (cont);
}
