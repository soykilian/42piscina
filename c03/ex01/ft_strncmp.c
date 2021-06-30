/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:57:56 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/30 14:16:36 by mclerico         ###   ########.fr       */
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
	return (ft_value(s1, n) - ft_value(s2, n));
}
