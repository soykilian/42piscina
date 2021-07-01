/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:32:01 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 22:16:29 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	unsigned int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;
	int	t;

	l = ft_strlen(base);
	if (nbr < l)
		 write(1, &base[nbr], 1);
	else
	{
		t = nbr % l;
		ft_putnbr_base(nbr / l, base);
		write(1, &base[t], 1);
	}
}
