#ifndef NUMBER_H
# define NUMBER_H

typedef struct s_numbers
{
	unsigned int		key;
	char				*value;
}	t_numbers;

typedef struct s_group
{
	int				pos;
	int				group;
	int				one;
	unsigned int	zeros;
	int				size;
	int				n_digits;
}	t_g;
#endif
