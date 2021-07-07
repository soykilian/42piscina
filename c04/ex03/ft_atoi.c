/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:59:07 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/07 12:33:24 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		cont;
	int		a;

	i = 0;
	cont = 0;
	a = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			cont++;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		a = (a * 10 + (str[i] - 48));
		i++;
	}
	if (cont % 2 != 0)
		a = a * -1;
	return (a);
}
