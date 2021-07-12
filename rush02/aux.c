/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:18:38 by dsanchez          #+#    #+#             */
/*   Updated: 2021/07/11 22:37:44 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "number.h"

int		fill_nums(t_numbers *nums, char *p);
void	ft_num(char unit, t_numbers *nums, int size, int i);
void	ft_mapping(unsigned int n, t_numbers *nums, int size, int index);

int	file_lines_n(char *p)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (p[i])
	{
		if (p[i] == '\n' && p[i + 1] != '\n')
			size++;
		i++;
	}
	return (size);
}

int	file_size(char *file_name)
{
	int		f;
	int		i;
	char	buf;

	f = open(file_name, O_RDONLY);
	i = 0;
	buf = 0;
	if (f > 1)
	{
		while (read(f, &buf, 1))
			i++;
		close(f);
	}
	return (i);
}

char	*ft_fill_pointer(char *file_name)
{
	char	*p;
	int		f;
	int		i;
	char	buf;

	p = malloc(file_size(file_name));
	f = open(file_name, O_RDONLY);
	buf = 0;
	i = 0;
	while (read(f, &buf, 1))
	{
		p[i] = buf;
		i++;
	}
	close(f);
	return (p);
}

int	ft_thousands(t_g n)
{
	int	sol;

	sol = n.zeros;
	while (n.group > 1)
	{
		sol *= 1000;
		n.group--;
	}
	return (sol);
}

void	ft_teens(char c, t_g n, t_numbers *nums, int i)
{
	ft_num(c, nums, n.size, i);
	if (n.group != 0)
		ft_mapping(n.zeros, nums, n.size, i);
}
