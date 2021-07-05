/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:40:28 by mclerico          #+#    #+#             */
/*   Updated: 2021/07/05 12:55:50 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_recursive_factorial (int n)
{
	if ( n < 0)
		return (0);
	else if (n == 0 || n == 1)
		return 1;
	else
		n = n * ft_recursive_factorial(n - 1);
	return (n);
}
