/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:33:28 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 20:13:28 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char str)
{
	int	i;
	int	chartrue;

	i = 0;
	chartrue = 1;
	if (str < 97 || str > 122)
		chartrue = 0;
	return (chartrue);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_is_lowercase(str[i]) == 1)
			str[i] -= 32;
		i++;
	}
	return (str);
}
