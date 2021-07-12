#include <unistd.h>
#include <stdio.h>
#include "comprobar_condiciones.h"
#include "essolucion.h"
#include "utils.h"
#include "comprobar_vistas.h"
void	print_table( char tablero[4][4]);
void	rascacielosBacktraking(char t[4][4], char i[4][4], int *sol, int IJ[2]);
int		aceptable(char t[4][4], char input[4][4], int IJ[2], char candidato);

void	print_table( char tablero[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			write(1, &tablero[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}

void	ft_backwards(int IJ[2], char t [4][4])
{
	if (IJ[1] > 0)
		IJ[1]--;
	else
	{
		IJ[1] = 3;
		IJ[0]--;
	}	
	t[IJ[0]][IJ[1]] = '0';
}

void	rascacielosBacktraking(char t[4][4], char i[4][4], int *sol, int IJ[2])
{
	char	c;

	if (esSolucion(t, i) == 1)
		*sol = 1;
	else
	{
		c = '1';
		if (IJ[1] == 4)
		{
			IJ[1] = 0;
			IJ[0]++;
		}
		while (c <= '4' && IJ[0] < 4 && IJ[1] < 4)
		{
			if (aceptable(t, i, IJ, c) == 1)
			{
				t[IJ[0]][IJ[1]++] = c;
				rascacielosBacktraking(t, i, sol, IJ);
				if (esSolucion(t, i) == 0)
					ft_backwards(IJ, t);
			}
			c++;
		}
	}
}

int	aceptable(char t[4][4], char input[4][4], int IJ[2], char candidato)
{
	int	i;
	int	j;
	int	correcto;

	i = 0;
	j = 0;
	correcto = 1;
	while (i < 4 && correcto == 1)
	{
		if (t[i][IJ[1]] == candidato)
			correcto = 0;
		i++;
	}
	while (j < 4 && correcto == 1)
	{
		if (t[IJ[0]][j] == candidato)
			correcto = 0;
		j++;
	}
	if (correcto == 1)
	{
		if (comprobarVistas(t, input, IJ, candidato) == 0)
			correcto = 0;
	}
	return (correcto);
}

int	main(int args, char **argv)
{
	int		i_j[2];
	char	tablero[4][4];
	int		solucion;
	char	params[4][4];

	i_j[0] = 0;
	i_j[1] = 0;
	solucion = 0;
	if (!comprueba_params(argv[1], params))
	{
		write (1, "Error k\n", 8);
		return (0);
	}
	if (args != 2)
	{
		write (1, "Error i\n", 8);
		return (0);
	}
	fill_table(tablero);
	rascacielosBacktraking(tablero, params, &solucion, i_j);
	if (solucion == 0)
		write (1, "Error j\n", 8);
	else
		print_table(tablero);
}
