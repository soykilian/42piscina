/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:36:46 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/11 22:36:58 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.h"
#include <stdlib.h>

int	str_len(char *p, int index)
{
	int		i;
	int		size;
	int		space;

	i = index;
	size = 0;
	space = 0;
	while (p[i] != '\n')
	{
		if (p[i] == 32 && space == 0)
		{
			i++;
			size++;
			space = 1;
		}
		else if (p[i] == 32 && space == 1)
			i++;
		else
		{
			space = 0;
			size++;
			i++;
		}
	}
	return (size);
}

char	*ft_get_string(char *p, int i)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc(str_len(p, i));
	while (p[i] != '\n')
	{
		if (p[i] == ' ' && str[j] != ' ')
		{
			str[j] = ' ';
			j++;
		}
		else if (p[i] > 32 && p[i] < 127)
		{
			str[j] = p[i];
			j++;
		}
		i++;
	}
	return (str);
}

int	fill_line(int *i, char *p, t_numbers *nums, int j)
{
	int	value;

	value = -1;
	while (p[*i] != '\n')
	{
		if (p[*i] > 47 && p[*i] < 58 && value == -1)
			nums[j].key = (nums[j].key * 10) + p[*i] - 48;
		else if (value == -1 && p[*i] == ':')
			value = 0;
		else if (p[*i] != 32 && value == 0)
		{
			nums[j].value = ft_get_string(p, *i);
			value = 1;
		}
		*i += 1;
	}
	return (value);
}

int	fill_nums(t_numbers *nums, char *p)
{
	int			i;
	int			j;
	int			value;

	j = -1;
	i = -1;
	while (p[++i])
	{
		value = -1;
		nums[++j].key = 0;
		value = fill_line(&i, p, nums, j);
		if (value != 1)
			return (0);
	}
	return (1);
}
