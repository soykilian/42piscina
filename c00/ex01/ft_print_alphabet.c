/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:36:42 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 12:48:13 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>   

void	ft_print_alphabet (void)
{
	int		x;
	char	letra;

	x = 26;
	letra = 'a';
	while (x != 0)
	{
		write(1, &letra, 1);
		letra++;
		x--;
	}
}
