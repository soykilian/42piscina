/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:00:30 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 13:05:27 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	    write(1, &c, 1);
}

int	check (int *a, int n )
{
	int	i;
	int	t;

	i = 0;
	t = 1;
	while (i < n - 1 && t == 1)
	{
		if (a[i] < a[i + 1])
		{
			i++;
		}
		else
		{
			t = 0;
			return (t);
		}
	}
	return (t);
}

void	ft_print_char(int *arr, int n)
{
	int		i;
	char	charf;

	i = 0;
	if (check(arr, n))
	{
		while (i < n)
		{
			charf = arr[i] + 48;
			ft_putchar(charf);
			i++;
		}
		if (arr[0] < 10 - n)
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_ones(void)
{
	int	ch_f;

	ch_f = 48;
	while (ch_f < 57)
	{
		write (1, &ch_f, 1);
		write(1, ", ", 2);
		ch_f++;
	}
	write(1, &ch_f, 1);
}

void	ft_print_combn( int n)
{
	int	arr[9];
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	if (n == 1)
		ft_ones();
	while (arr[0] <= (10 - n) && n > 1)
	{
		ft_print_char(arr, n);
		arr[n - 1]++;
		i = n;
		while (i-- != 0 && n - 1 )
		{
			if (arr[i] > 9)
			{
				arr[i - 1]++;
				arr[i] = 0;
			}
		}
	}
}
