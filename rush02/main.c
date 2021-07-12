/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:37:53 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/11 22:39:14 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_fill_pointer(char *file_name);
int		file_size(char *file_name);
int		file_lines_n(char *file_name);
int		fill_nums(t_numbers *nums, char *p);
int		check_args(int argc, char **argv);
void	ft_mapping(unsigned int n, t_numbers *nums, int size, int index);
void	ft_three(t_g n, char d, t_numbers *nums, int i);
void	ft_num(char unit, t_numbers *nums, int size, int i);
void	ft_print(char *str);
int		ft_thousands(t_g n);
void	ft_teens(char c, t_g n, t_numbers *nums, int i);

int	ft_fill_zeros(char *argv, int *i, t_g n, t_numbers *nums)
{
	if (n.n_digits == 1 && argv[0] == '0')
	{
		ft_mapping(0, nums, n.size, *i);
		return (1);
	}
	if (argv[*i] == '0')
	{
		if (n.pos == 0 && n.one)
			ft_mapping(n.zeros, nums, n.size, *i + 1);
		*i += 1;
		return (2);
	}
	return (0);
}

int	ft_fill_digits(int *i, t_g n, char *argv, t_numbers *nums)
{
	if (n.pos == 1 && argv[*i] == '1')
	{
		ft_teens(argv[*i + 1], n, nums, *i);
		*i += 2;
		return (0);
	}
	else
		ft_three(n, argv[*i], nums, *i);
	if (n.pos == 0 && n.group != 0)
		ft_mapping(n.zeros, nums, n.size, *i + 1);
	return (1);
}

void	ft_get_nums(char *p, char *argv, t_g n, t_numbers *nums)
{
	int			i;
	int			check;

	i = 0;
	check = 0;
	fill_nums(nums, p);
	while (argv[i])
	{
		n.zeros = 1000;
		n.group = (n.n_digits - 1 - i) / 3;
		n.pos = (n.n_digits - 1 - i) % 3;
		n.zeros = ft_thousands(n);
		if (n.pos == 2)
			n.one = 0;
		if (argv[i] != '0')
			n.one = n.group;
		check = ft_fill_zeros(argv, &i, n, nums);
		if (check == 1)
			break ;
		else if (check == 2)
			continue ;
		if (ft_fill_digits(&i, n, argv, nums) == 0)
			continue ;
		i++;
	}
}

t_g	fill_n(char **argv)
{
	t_g				n;

	n.n_digits = 0;
	n.pos = 0;
	n.group = 0;
	n.zeros = 1000;
	n.one = 0;
	while (argv[1][n.n_digits])
		n.n_digits++;
	return (n);
}

int	main(int argc, char **argv)
{
	char			*p;
	t_numbers		*nums;
	t_g				n;

	if (!check_args(argc, argv))
		return (0);
	if (argc == 3)
		p = ft_fill_pointer(argv[2]);
	else
		p = ft_fill_pointer("numbers.dict");
	n = fill_n(argv);
	n.size = file_lines_n(p);
	nums = malloc(n.size * 16);
	if (nums == NULL)
		return (0);
	if (!fill_nums(nums, p))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	ft_get_nums(p, argv[1], n, nums);
	free(nums);
	free(p);
	return (0);
}
