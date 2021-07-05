/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:44:00 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/05 18:45:42 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_prime(int nb)
{
	int	i;
	int	cont;

	i = 1;
	cont = 0;
	while (i < nb + 1)
	{
		if (nb % i == 0)
			cont++;
		i++;
	}
	if (cont <= 2)
		return (1);
	else
		return (0);
}