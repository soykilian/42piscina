/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:32:24 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 19:33:00 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	chartrue;

	i = 0;
	chartrue = 1;
	while (chartrue == 1 && str[i] != '\0' )
	{
		if (str[i] < 32 || str[i] > 126)
			chartrue = 0;
		i++;
	}
	return (chartrue);
}
