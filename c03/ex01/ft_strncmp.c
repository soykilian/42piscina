/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:57:56 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/28 19:01:03 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	result;

	result = 1;
	while (*s1 || *s2)
	{
		if (*s1 == *s2)
			result = 0;
		else
		{
			if (*s1 == 0 && *s2 != 0)
				return (*s1 - *s2);
			else if (*s2 == 0 && *s1 != 0)
				return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (result);
}
