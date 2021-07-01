/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:57:56 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/30 21:12:11 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_value (char *src, unsigned int n)
{
	int				c;
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		c += src[i];
		i++;
	}
	return (c);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n && *s1 == *s2 && *s1 && *s2)
	{
		s2++;
		s1++;
	}
	return (s1 - s2);
}
