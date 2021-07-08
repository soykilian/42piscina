/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:58:40 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/08 17:14:23 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	n;

	i = 0;
	n = min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	range = malloc(8 * max - min);
	if (!range)
		return (-1);
	while (i < max - n)
	{
		range[i] = malloc(4);
		*range[i] = n++;
		i++;
	}
	return (max - min);
}
