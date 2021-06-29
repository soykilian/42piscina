/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:59:35 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/29 13:18:18 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char str)
{
	int	chartrue;

	chartrue = 1;
	if (str > 64 && str < 90)
		chartrue = 0;
	return (chartrue);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_is_uppercase(str[i]) == 1)
			str[i] += 32;
		i++;
	}
	return (str);
}
