/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:38:03 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/11 22:38:06 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "number.h"

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_mapping(unsigned int n, t_numbers *nums, int size, int index)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nums[i].key == n)
		{
			if (index != 0)
				write(1, " ", 1);
			ft_print(nums[i].value);
			break ;
		}
		i++;
	}
}

void	ft_three(t_g n, char d, t_numbers *nums, int i)
{
	if (d == 48)
		return ;
	else if (n.pos == 2)
	{
		ft_mapping(d - 48, nums, n.size, i);
		ft_mapping(100, nums, n.size, i + 1);
	}
	else if (n.pos == 1)
		ft_mapping((d - 48) * 10, nums, n.size, i);
	else if (n.pos == 0)
		ft_mapping(d - 48, nums, n.size, i);
}

void	ft_num(char unit, t_numbers *nums, int size, int i)
{
	int	num;

	num = 10;
	num += unit - 48;
	ft_mapping(num, nums, size, i);
}
