/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:57:56 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/05 11:06:04 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n && *s1 == *s2 && *s1 && *s2)
	{
		s2++;
		s1++;
	}
	if (i < n)
		return ((unsigned char)s1 - (unsigned char)s2);
	else
		return (0);
}
""