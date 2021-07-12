#include "comprobar_vistas.h"
int	esSolucion(char tablero[4][4], char input[4][4])
{
	int	correcto;
	int	filCol[2];

	correcto = 1;
	filCol[0] = 0;
	filCol[1] = 0;
	while (filCol[0] < 4 && correcto == 1)
	{
		filCol[1] = 0;
		while (filCol[1] < 4 && correcto == 1)
		{
			if (tablero[filCol[0]][filCol[1]] == '0')
			{
				correcto = 0;
			}
			else
			{
				if (comprobarVistas(tablero, input, filCol, '0') == 0)
					correcto = 0;
			}
			filCol[1]++;
		}
		filCol[0]++;
	}
	return (correcto);
}
