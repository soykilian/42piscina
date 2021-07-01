/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:07:39 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/01 13:05:27 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (dest[j] != 0)
	{
		j++;
	}
	while (i < nb && src[i] != 0)
	{
		dest[j++] = src[i];
		i++;
	}
	dest[j] = '\0';
}

