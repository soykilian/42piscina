/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:05:24 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/30 19:28:35 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_lowercase(char str)
{
	if (str > 97 && str < 122)
		return (1);
	return (0);
}

int	is_uppercase(char str)
{
	if (str > 64 && str < 91)
		return (1);
	return (0);
}

int	is_alphabetic(char str)
{
	if (str > 47 && str < 58)
		return (1);
	else if ((str > 64 && str < 91) || (str > 96 && str < 123))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (is_lowercase(str[0]))
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (is_lowercase(str[i]))
		{
			if (is_alphabetic(str[i + 1]) && i == 0)
				str[i + 1] -= 32;
			else if (!is_alphabetic(str[i - 1]))
				str[i] -= 32;
		}
		else if (is_uppercase(str[i]) && is_alphabetic(str[i - 1]))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
