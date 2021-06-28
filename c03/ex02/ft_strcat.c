/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:11:46 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/28 21:09:17 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (dest[j] != 0)
	{
		j++;
	}
	while (src[i] != 0)
	{
		c = src[i++];
		dest[j++] = c;
	}
	dest[j] = '\0';
	return (dest);
}

int	main(void)
{
	char text1[] = "Victoria\0";
	char text2[] = "Maria\0";
	char	*s1;
	char	*s2;
	
	s1 = text1;
	s2 = text2;
	ft_strcat(s2, s1);
}