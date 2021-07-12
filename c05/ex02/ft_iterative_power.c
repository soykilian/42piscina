/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:01:24 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/08 17:35:28 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	n;

	n = nb;
	i = 0;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		while (i < power - 1)
		{
			n *= nb;
			i++;
		}
	}
	return (n);
}
