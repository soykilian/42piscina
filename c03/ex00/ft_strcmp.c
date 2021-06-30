/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:35:25 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/30 14:22:25 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_value(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != 0)
	{
		c += str[i];
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	return (ft_value(s1) - ft_value(s2));
}
