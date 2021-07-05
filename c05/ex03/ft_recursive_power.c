/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:50:18 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/05 16:34:04 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_recursive_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power == 0)
		return (1);
	else if (power == 1)
	   return (n);	
	else
		n *= ft_recursive_power(n, power - 1);
	return (n);
}
