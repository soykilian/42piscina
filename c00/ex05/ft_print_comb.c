/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 22:26:32 by mariavictor       #+#    #+#             */
/*   Updated: 2021/06/26 18:41:46 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_printchar( int *num)
{
	int		j;
	char	ch_f;

	j = 0;
	while (j < 3)
	{
		ch_f = num[j] + 48;
		j++;
		write(1, &ch_f, 1);
	}
	if (num[0] < 7)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	num[3];

	while (num[0] < 8)
	{
		if (num[0] < num[1] && num[1] < num[2])
			ft_printchar(num);
		if (num[2] < 9)
			num[2]++;
		else
		{
			num[2] = 0;
			if (num[1] < 9)
				num[1]++;
			else
			{
				num[1] = 0;
				num[0]++;
			}
		}
	}
}
