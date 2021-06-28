/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:07:55 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/28 13:20:26 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	is_printable(char str)
{
	int	chartrue;

	chartrue = 1;
	if (str < 32 || str > 126)
		chartrue = 0;
	return (chartrue);
}

void	ft_char_to_hex(char src)
{	
	char	a[2];
	char	*p;
	int		dec;
	int		t;
	int		k;

	a[0] = '0';
	a[1] = '0';
	p = a;
	dec = src;
	k = 1;
	while (dec != 0)
	{
		t = dec % 16;
		if (t < 10)
			t = t + 48;
		else
			t = t + 55;
		p[k--] = t;
		dec = dec / 16;
	}
	write(1, p, 2);
}

void	ft_dec_to_hex(char *src, int *i)
{
	int		j;
	int		cont;

	j = 0;
	cont = 0;
	while (j < 16 && src[j] != 0)
	{
		ft_char_to_hex(src[j]);
		if (cont++ == 1)
		{
			write (1, " ", 1);
			cont = 0;
		}
		j++;
	}
	write(1, "\n", 1);
	*i += j;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		*dir;
	int		*i;
	char	*co;
	int		inum;

	co = addr;
	inum = 0;
	i = &inum;
	while (*i < size)
	{
		//dir = &addr;
		ft_dec_to_hex(co, i);
		if (*i != size)
			co += 16;
	}
	return (addr);
}

int main(void)
{
	char	f[46] = "tu puta madre moulinette de los kojones basura";
	char	*pi;
	pi = f;
	ft_print_memory(pi, 46);


}