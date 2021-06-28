/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:57:56 by mclerico          #+#    #+#             */
/*   Updated: 2021/06/28 20:51:01 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (*s1 || *s2)
	{
		if (*s1 == *s2 && i == n -1)
			result = 0;
		else
		{
			if (*s1 == 0 && *s2 != 0)
				return (*s1 - *s2);
			else if (*s2 == 0 && *s1 != 0)
				return (*s1 - *s2);
		}
		i ++;
		s1++;
		s2++;
	}
	return (result);
}

int main (void)
{
	char text1[] = "Maria";
	char text2[] = "MariaVi";
	char	*s1;
	char	*s2;
	int result = 1;
	s1 = text1;
	s2 = text2;
	result = ft_strncmp(s1, s2, 6);

}
