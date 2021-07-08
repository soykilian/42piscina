/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:45:47 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/08 17:14:39 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	p = malloc(max - min);
	if (!p)
		return (NULL);
	while (min < max)
	{
		p[i++] = min++;
		printf("%d", p[i - 1]);
	}		
	return (p);
}
