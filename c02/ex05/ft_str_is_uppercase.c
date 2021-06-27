/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:19:17 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 19:21:38 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	chartrue;

	i = 0;
	chartrue = 1;
	while (chartrue == 1 && str[i] != '\0' )
	{
		if (str[i] < 64 || str[i] > 90)
			chartrue = 0;
		i++;
	}
	return (chartrue);
}
