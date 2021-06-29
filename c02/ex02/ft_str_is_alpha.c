/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:09:50 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/29 13:21:21 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	chartrue;

	i = 0;
	chartrue = 1;
	while (chartrue == 1 && str[i] != '\0' )
	{
		if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
			chartrue = 1;
		else
			chartrue = 0;
		i++;
	}
	return (chartrue);
}
