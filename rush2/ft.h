/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmottet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:42:11 by nmottet-          #+#    #+#             */
/*   Updated: 2021/07/10 20:30:45 by nmottet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_list
{
	int		nb;
	char	*val;
}			t_list;

int	ft_atoi(const char *str);
char *ft_strdup(char *src);
void ft_putstr(char *str);
char *ft_getnb(int fd);
char *ft_getval(int fd, char *c);
t_list *process(char *file);

#endif
