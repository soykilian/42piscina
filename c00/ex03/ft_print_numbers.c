/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:43:31 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 12:53:01 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>   

void	ft_print_numbers( void )
{
	int		num;
	char	char_f;

	num = 0;
	while (num < 10)
	{
		char_f = num + 48;
		write(1, &char_f, 1);
		num++;
	}
}
