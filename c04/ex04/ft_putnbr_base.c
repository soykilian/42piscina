/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:32:01 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/05 21:28:08 by mclerico         ###   ########.fr       */
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

int	check_base(char *base)
{
	int	l;
	int	i;
	int	j;

	i = 0;
	j = 0;
	l = ft_strlen(base);
	if (l < 2)
		return (0);
	while (i < l)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != 0)
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	ft_base_change(unsigned int n, char *base)
{
	unsigned int	l;
	int				t;

	l = ft_strlen(base);
	if (n < l)
		 write(1, &base[n], 1);
	else
	{
		t = n % l;
		ft_base_change(n / l, base);
		write(1, &base[t], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;

	n = 0;
	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		n = nbr * -1;
		write(1, "-", 1);
	}
	else
		n = nbr;
	ft_base_change(n, base);
}
