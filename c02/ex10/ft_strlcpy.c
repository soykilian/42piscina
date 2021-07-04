/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:19:01 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 20:05:53 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *str)
{
	unsigned int		c;

	c = 0;
	while (*str != 0)
	{
		c++;
		str++;
	}
	return (c);
}

char	*ft_copy(char *src, char *dest, unsigned int size)
{
	unsigned int	i;
	char			*s;
	char			*d;

	s = src;
	d = dest;
	i = 0;
	while (i++ < size)
	{
		*d++ = *s++;
	}	
	return (d);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	l;

	l = ft_len(src);
	if (l + 1 < size)
	{
		ft_copy(src, dest, l + 1);
	}
	else if (size != 0)
	{
		ft_copy(src, dest, size - 1);
		dest[size - 1] = 0;
	}
	return (l);
}
