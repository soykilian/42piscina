#include <unistd.h>
#include <stdio.h>



int	comprueba_params(int n, char *cond, char params[4][4])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	if (n != 2)
		return (0);
	while (i < 31)
	{
		if (i % 2 != 0 && cond[i] != 32)
			return (0);
		else if (i % 2 != 0 && cond[i] == 32)
			i++;
		else if ((cond[i] > 48 && cond[i] < 53) && (i % 2 == 0))
		{
			params[k - 1][j] = cond[i];
			j++;
			if( j % 4 == 0){
				j = 0;
				k++;
			}
			i++;
		}
		else 
			return (0);
	}
	return (1);
}

void	print_table( char tablero[4][4])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			write(1, &tablero[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}

int	main(int args, char **argv)

{
	int		i;
	int		j;
	char	tablero[4][4];
	int		*solucion;
	char	params[4][4];

	i = 0;
	j = 0;
	solucion = 0;
	if (!comprueba_params(args, argv[1], params))
	{
		write (1, "Error\n", 6);
		return (0);
	}
;	while (i < 4)
	{
		while (j < 4)
			tablero[i][j++] = '0';
		if ( j == 4)
		{
			i++;
			j = 0;
		}
	}
//	rascacielosBacktraking(tablero, params, &solucion, 0, 0);
//	if (solucion == 0)
//		write (1, "ERROR\n", 6);
//	else
		print_table(params);
}
