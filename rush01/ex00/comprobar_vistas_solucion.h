char	vista_fila_izquierda(char tablero[4][4], int posI)
{
	int		j;
	char	mayor;
	char	vistafizq;

	vistafizq = '0';
	mayor = '0';
	j = 0;
	while (j <= 3)
	{
		if (mayor < tablero[posI][j] && tablero[posI][j] != 0)
		{
			vistafizq++;
			mayor = tablero[posI][j];
		}
		j++;
	}
	return (vistafizq);
}

char	vista_fila_derecha(char tablero[4][4], int posI)
{
	int		j;
	char	mayor;
	char	vistafdcha;

	vistafdcha = '0';
	mayor = '0';
	j = 3;
	while (j >= 0)
	{
		if (mayor < tablero[posI][j] && tablero[posI][j] != 0)
		{
			vistafdcha++;
			mayor = tablero[posI][j];
		}
		j--;
	}
	return (vistafdcha);
}

char	vista_col_superior(char tab[4][4], int posJ)
{
	int		i;
	char	mayor;
	char	vistacsup;

	vistacsup = '0';
	mayor = '0';
	i = 0;
	while (i <= 3)
	{
		if (mayor < tab[i][posJ] && tab[i][posJ] != 0 && tab[i - 1][posJ] != 0)
		{
			vistacsup++;
			mayor = tab[i][posJ];
		}
		i++;
	}
	return (vistacsup);
}

char	vista_col_inferior(char tablero[4][4], int posJ)
{
	int		i;
	char	mayor;
	char	vistacinf;

	vistacinf = '0';
	mayor = '0';
	i = 3;
	while (i >= 0)
	{
		if (mayor < tablero[i][posJ] && tablero[i][posJ] != 0 )
		{
			vistacinf++;
			mayor = tablero[i][posJ];
		}
		i--;
	}
	return (vistacinf);
}

int	comprobarVistasSolucion(char tablero[4][4], char colUp[4], char coldown[4], char rowLeft[4], char rowRight[4], int posI, int posJ)
{
	char	vistafizq;
	char	vistafder;
	char	vistacsup;
	char	vistacinf;

	vistafizq = vista_fila_izquierda;
	vistafder = vista_fila_derecha;
	vistacsup = vista_fila_izquierda;
	vistacinf = vista_fila_izquierda;
		//vista de la fila izquierda
	/*while(j <= 3)
	{
		if (mayor < tablero[posI][j] && tablero[posI][j] != 0 )
		{
			vistaLIzq++;
			mayor = tablero[posI][j];
		}
		j++;
	}
	*/
	//vista de la fila derecha
	/*j = 3;
	mayor = '0';
	while (j >= 0)
	{
		if (mayor < tablero[posI][j] && tablero[posI][j] != 0)
		{
			vistaLDer++;
			mayor = tablero[posI][j];
		}
		j--;
	}
	*/
	//vista de la columna superior
	/*
	mayor = '0';
	while (i <= 3)
	{
		if (mayor < tablero[i][posJ] && tablero[i][posJ] != 0 && tablero[i-1][posJ] != 0)
		{
			vistaASup++;
			mayor = tablero[i][posJ];
		}
		i++;
	}
	*/
	//vista de la columna inferior
	/*
	i = 3;
	mayor = '0';
	while (i >= 0)
	{
		if (mayor < tablero[i][posJ] && tablero[i][posJ] != 0 )
		{
			vistaAInf++;
			mayor = tablero[i][posJ];
		}
		i--;
	}
	*/
	if (colUp[posJ] == vistacsup && coldown[posJ] == vistacinf && rowLeft[posI] == vistafizq && rowRight[posI] == vistafder)
		return (1);
	else
		return (0);
	return (0);
}
