/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:48:26 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/27 19:59:08 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	    write(1, &c, 1);
}

int	is_printable(char str)
{
	int	chartrue;

	chartrue = 1;
	if (str < 32 || str > 126)
		chartrue = 0;
	return (chartrue);
}

void	ft_dec_to_hex(int n, char *p)
{
	int		i;
	int		t;
	int		dec;

	i = 1;
	dec = n;
	while (dec != 0)
	{
		t = dec % 16;
		if (t < 10)
			t = t + 48;
		else
			t = t + 55;
		p[i--] = t;
		dec = dec / 16;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*p;
	char	a[2];
	char	*dest;

	dest = str;
	i = 0;
	a[0] = '0';
	a[1] = '0';
	p = a;
	while (str[i] != 0)
	{
		if (is_printable(str[i]) == 0)
		{
			ft_dec_to_hex(str[i], p);
			ft_putchar('\\');
			ft_putchar(p[0]);
			ft_putchar(p[1]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
