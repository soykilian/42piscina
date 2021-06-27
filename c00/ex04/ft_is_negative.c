/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:51:27 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/26 12:47:52 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>   
#include<unistd.h>

void	ft_is_negative (int n)
{
	if (n >= 0 )
	{
		 write(1, "P", 1);
	}
	else
	{
		write(1, "N", 1);
	}
}
