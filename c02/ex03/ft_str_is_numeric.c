/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:12:16 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 20:18:48 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	chartrue;

	i = 0;
	chartrue = 1;
	while (chartrue == 1 && str[i] != '\0' )
	{
		if (str[i] < 49 || str[i] > 57)
			chartrue = 0;
		i++;
	}
	return (chartrue);
}
int	main(void)
{
	char texto[] = "";
	char *pi;

	pi = texto;
	int correcto = ft_str_is_numeric(pi);
	printf("%d", correcto);
}
