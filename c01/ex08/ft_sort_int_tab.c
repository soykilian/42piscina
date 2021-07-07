/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:09:21 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/07 10:46:37 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	ord;
	int	act;
	int	sig;

	i = 0;
	ord = 0;
	while (ord == 0 )
	{
		ord = 1;
		while (i < size - 1)
		{
			act = tab[i];
			sig = tab[i + 1];
			if (act > sig)
			{
				tab[i + 1] = act;
				tab[i] = sig;
				ord = 0;
			}
			i++;
		}
		i = 0;
	}
}
