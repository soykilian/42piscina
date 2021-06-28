/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:35:25 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/28 18:59:17 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	result = 1;
	while (*s1 || *s2)
	{
		if (*s1 == *s2)
			result = 0;
		else
		{
			if (*s1 == 0 && *s2 != 0)
				return (*s1 - *s2);
			else if (*s2 == 0 && *s1 != 0)
				return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (result);
}

int main (void)
{
	char text1[] = "Maria";
	char text2[] = "Maria";
	char	*s1;
	char	*s2;
	int result = 1;
	s1 = text1;
	s2 = text2;
	result = ft_strcmp(s1, s2);

}