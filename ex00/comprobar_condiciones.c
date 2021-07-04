#include "comprobar_vistas.h"

int	colULt (char tablero[4][4], char input[4][4], int IJ[2])
{
	int	correcto;

	if (input[2][IJ[0]] == vista_fila_izquierda(tablero, IJ[0])
		&& input[3][IJ[0]] == vista_fila_derecha(tablero, IJ[0]))
		correcto = 1;
	else
	{
		correcto = 0;
	}
	return (correcto);
}

int	filUlt (char tablero[4][4], char input[4][4], int IJ[2])
{
	int	correcto;

	if (input[0][IJ[1]] == vista_col_superior(tablero, IJ[1])
		&& input[1][IJ[1]] == vista_col_inferior(tablero, IJ[1]))
		correcto = 1;
	else
	{
		correcto = 0;
	}
	return (correcto);
}
