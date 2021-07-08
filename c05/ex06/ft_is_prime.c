/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:44:00 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/07 20:22:57 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb && i < 46340)
		i++;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	cont;

	i = 1;
	cont = 0;
	if (nb < 2)
		return (0);
	while (++i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
	}
	return (nb);
}
