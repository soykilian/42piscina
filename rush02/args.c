/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:37:07 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/11 22:37:14 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	ft_atoi(char *str)
{
	int		i;
	int		cont;
	long	a;

	i = 0;
	cont = 0;
	a = 0;
	while (str[i])
	{
		if (!(str[i] > 47 && str[i] < 58))
			return (-1);
		else
			a = (a * 10 + (str[i] - 48));
		i++;
	}
	if (a > 4294967295)
		return (-1);
	if (i > 10)
		return (-1);
	return (a);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_atoi(argv[1]) < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
