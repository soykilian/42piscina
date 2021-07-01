/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:07:55 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 12:17:14 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_char_to_hex(unsigned char src)
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
			t = t + 87;
		p[k--] = t;
		dec = dec / 16;
	}
	write(1, p, 2);
}

void	print_str(char *src, unsigned int *i, unsigned int size)
{
	int		j;
	int		a;

	j = 0;
	if (size - *i < 16)
		a = size - *i;
	else
		a = 16;
	while (j < a)
	{
		if (src[j] > 31 && src[j] < 127)
			write(1, &src[j], 1);
		else
			write(1, ".", 1);
		j++;
	}
	write(1, "\n", 1);
}

void	dec_char_hex(unsigned long n)
{
	unsigned long		dec;
	char				*pi;
	char				a[16];
	int					i;
	int					t;

	dec = 0;
	i = 0;
	t = 0;
	while (i++ < 16)
		a[i] = '0';
	pi = a;
	i = 15;
	dec = n;
	while (dec != 0 || i > -1)
	{
		t = dec % 16;
		if (t < 10)
			t = t + 48;
		else
			t = t + 87;
		pi[i--] = t;
		dec = dec / 16;
	}
	write(1, pi, 16);
}

void	ft_dec_to_hex(char *src, unsigned int *i, unsigned int size)
{
	int		j;
	int		cont;
	int		a;

	j = 0;
	cont = 0;
	if (size - *i < 16)
		a = size - *i;
	else
		a = 16;
	while (j < a)
	{
		ft_char_to_hex((unsigned char)src[j++]);
		if (cont++ == 1)
		{
			write (1, " ", 1);
			cont = 0;
		}
	}
	cont = 0;
	if (j != 16)
		while (cont++ < 40 - (j / 2 + 2 * j))
			write(1, " ", 1);
	print_str(src, i, size);
	*i += j;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		*i;
	char				*co;
	unsigned int		inum;
	long unsigned		dir;

	co = addr;
	inum = 0;
	i = &inum;
	while (*i < size)
	{	
		dir = (long unsigned)co;
		dec_char_hex(dir);
		write(1, ": ", 2);
		ft_dec_to_hex(co, i, size);
		if (*i != size)
			co += 16;
	}
	return (addr);
}
