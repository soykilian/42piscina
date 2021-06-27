/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:05:24 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/27 13:01:20 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

	chartrue = 1;
	if (str < 32 || str > 47)
		chartrue = 0;
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
		printf("%c", str[i]);
		i++;
	}
	return (str);
}

int	main(void)
{
	char texto[] = "me llamo ? Mar0ia-victoria+clerico";
	char testo[]  = "0";
	char *pi;
	char *p2;

	pi = texto;
	p2 = testo;
	p2 = ft_strcapitalize(pi);

}