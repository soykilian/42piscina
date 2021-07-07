/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:13:51 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/07 15:45:23 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	int	cont;

	cont = 0;
	while (y <= 9)
	{
		if (is_valid(x, y, p))
		{
			p[x] = y + 48;
			if (x == 9)
			{
				write(1, p, 10);
				write(1, "\n", 1);
				cont++;
				p[x] = 0;
				return (0);
			}
			if (solve_puzzle(p, x + 1, 0))
				return (1);
			p[x] = 0;
		}
		y++;
	}	
	return (cont);
}

int	ft_ten_queens_puzzle(void)
{
	char	p[10];
	int		x;
	int		y;
	int		cont;

	x = 0;
	y = 0;
	cont = solve_puzzle(p, x, y);
	return (cont);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
