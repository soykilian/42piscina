/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:55:20 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/07 14:01:41 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	**sort_argv(char **argv, int n)
{
	int		i;
	char	*aux;
	int		ord;

	i = 1;
	ord = 0;
	while (ord == 0)
	{
		ord = 1;
		while (i < n - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				aux = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = aux;
				ord = 0;
			}
			i++;
		}
		i = 1;
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	argv = sort_argv(argv, argc);
	while (i < argc)
	{
		while (argv[i][j] != 0)
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
