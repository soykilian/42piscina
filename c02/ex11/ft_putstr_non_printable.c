/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:48:26 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/29 14:21:09 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	    write(1, &c, 1);
}

int	is_printable(unsigned char str)
{
	int	chartrue;

	chartrue = 1;
	if (str < 32 || str > 126)
		chartrue = 0;
	return (chartrue);
}

void	ft_dec_to_hex(unsigned char n)
{
	char	a[2];
	char	*pi;
	int		t;
	int		k;
	int		dec;

	a[0] = '0';
	a[1] = '0';
	pi = a;
	k = 1;
	dec = n;
	while (dec != 0)
	{
		t = dec % 16;
		if (t < 10)
			t = t + 48;
		else
			t = t + 87;
		pi[k--] = t;
		dec = dec / 16;
	}
	write(1, pi, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	*p;
	unsigned char	a[2];
	char			*dest;

	dest = str;
	i = 0;
	a[0] = '0';
	a[1] = '0';
	p = a;
	while (str[i] != 0)
	{
		if (is_printable(str[i]) == 0)
		{
			ft_putchar('\\');
			ft_dec_to_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
