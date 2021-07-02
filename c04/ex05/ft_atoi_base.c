/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base..c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:14:29 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/02 10:57:32y mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	unsigned int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

char	*ft_x_16(char *str, char *base, int lbase)
{
	int		i;
	int		j;
	char	*base_16;
	int		ls;

	base_16 = "0123456789abcdf";
	i = 0;
	j = 0;
	ls = ft_strlen(str);
	while (j < lbase)
	{
		if (str[i] == base[j])
		{
			str[i] = base_16[j];
			j = 0;
			if (i == ls)
				break ;
			i++;
		}
		else
			j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int		lbase;
	int		i;
	int		a;
	char	c;

	lbase = ft_strlen(base);
	i = 0;
	a = 0;
	str = ft_x_16(str, base, lbase);
	while (str[i] != 0)
	{
		if (str[i] > 57)
			c = str[i] - 87;
		else
			c = str[i] - 48;
		a = (c + a) * lbase;
		i++;
	}
	return (a / lbase);
}

int main(void)
{
	char base[5] = "mavi\0";
	char str[6] = "vviam\0";

	printf("%d", ft_atoi_base(str, base));
	return (0);
}
