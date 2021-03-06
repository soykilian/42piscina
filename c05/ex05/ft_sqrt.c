/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:39:46 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/09 12:54:17 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	max;
	int	n;

	n = 0;
	i = 1;
	max = 46340;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (i * i <= nb && i <= max)
	{
		n = i * i;
		if (n == nb)
			return (i);
		i++;
	}
	return (0);
}
