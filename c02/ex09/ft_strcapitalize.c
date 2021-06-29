/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:05:24 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/29 13:11:42 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char str)
{
	int	i;
	int	chartrue;

	i = 0;
	chartrue = 1;
	if (str < 97 || str > 122)
		chartrue = 0;
	return (chartrue);
}

int	is_punct(char str)
{
	int	chartrue;

	chartrue = 0;
	if (str > 47 && str < 123)
	{
		if ((str > 57 && str < 65) || (str > 90 && str < 97))
			chartrue = 1;
	}
	else
		chartrue = 1;
	return (chartrue);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (is_lowercase(str[0]) == 1)
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (is_punct(str[i]) == 1)
		{
			if (is_lowercase(str[i + 1]) == 1)
				str[i + 1] -= 32;
		}
		i++;
	}
	return (str);
}
