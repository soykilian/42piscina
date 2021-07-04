int	esSolucion(char tablero[4][4], char *colUp, char *coldown, char *rleft, char *rright)
{
	int	correcto;
	int	i;
	int	j;

	correcto = 1;
	i = 0;
	j = 0;
	while (i < 4 && correcto == 1)
	{
		while (j < 4 && correcto == 1)
		{
			if (tablero[i][j] == '0')
			{
				correcto = 0;
			}
			else
			{
				if (comprobarVistasSolucion(tablero, colUp, coldown, rleft, rright, i, j) == 0)
					correcto = 0;
			}
			j++;
		}
		i++;
	}
	return (correcto);
}
