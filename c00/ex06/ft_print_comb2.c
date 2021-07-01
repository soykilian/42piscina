/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:40:44 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/30 19:53:48 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_array(char *a)
{
	a[0] = '0';
	a[1] = '/';
	a[2] = ' ';
	a[3] = '0';
	a[4] = '0';
	a[5] = ',';
	a[6] = ' ';
}

void	update_rigth_num(char *a)
{
	while (a[3] <= '9')
	{
		++a[4];
		if (a[4] > '9')
		{
			a[4] = '0';
			++a[3];
			if (a[3] <= '9')
				write(1, a, 7);
		}
		else if (a[0] == '9' && a[1] == '8' && a[3] == '9' && a[0] == '9')
		{
			write(1, a, 5);
		}
		else
		{
			write(1, a, 7);
		}		
	}
}

void	ft_print_comb2(void)
{
	char	a[7];

	fill_array(a);
	while (a[0] <= '9')
	{
		++a[1];
		if (a[1] > '9')
		{
			a[1] = '0';
			++a[0];
		}
		a[3] = a[0];
		a[4] = a[1];
		update_rigth_num (a);
	}	
}
