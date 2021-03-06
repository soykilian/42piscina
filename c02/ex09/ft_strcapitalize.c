/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:05:24 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 13:58:23 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alpha_num(char str)
{
	if (str > 47 && str < 58)
		return (1);
	else if ((str > 64 && str < 91) || (str > 96 && str < 123))
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char str)
{
	if (str > 64 && str < 91)
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char str)
{
	if (str > 96 && str < 123)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (ft_str_is_lowercase(str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_str_is_lowercase(str[i]))
		{
			if ((!(is_alpha_num(str[i - 1]))))
				str[i] -= 32;
		}
		else if (ft_str_is_uppercase(str[i]) && is_alpha_num(str[i - 1]))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
