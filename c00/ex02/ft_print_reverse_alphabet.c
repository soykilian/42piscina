/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:36:53 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 12:48:08 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>    
#include <unistd.h>

void	ft_print_reverse_alphabet (void)
{
	int		x;
	char	letra;

	x = 0;
	letra = 'z';
	while (x != 26)
	{
		write(1, &letra, 1);
		letra--;
		x++;
	}
}
