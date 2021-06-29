/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:18:53 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/29 11:24:51 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length(char *str)
{
	int		length;
	int		j;

	j = 0;
	length = 0;
	while (str[j] != '\0')
		j++;
	length = j;
	return (length);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*index;
	char	null[1];

	i = 0;
	j = 0;
	index = str;
	while (str[i] != '\0' || (length(str) - i) >= length(to_find))
	{
		while (str[i] == to_find[j] && (str[i] != '\0' || to_find[j] != 0 ))
		{
			if (j == 0)
				index += i;
			j++;
			i++;
			if (j == length(to_find))
				return (index);
		}
		j = 0;
		i++;
	}
	if (j != length(to_find))
		index = null;
	return (index);
}

int	main(void)
{
	char 	text1[] = "Mariavicky\0";
	char 	text2[] = "vicky\0";
	char	*s1;
	char	*s2;

	s1 = text1;
	s2 = text2;
	ft_strstr(s1, s2);
}