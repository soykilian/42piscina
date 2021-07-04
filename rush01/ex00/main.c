#include <unistd.h>
#include <stdio.h>
#include <comprobar_vistas_solucion.h>
#include <essolucion.h>
//void parametros1(char *colUp1, char *coldown1, char *rowLeft1, char *rowRight1);
void	parametros(void);
int		aceptable(char tablero[4][4], char colUp[4], char coldown[4], char rowLeft[4], char rowRight[4], int  j, int i, char candidato);
int		esSolucion(char tablero[4][4],char *colUp, char *coldown, char *rowLeft, char *rowRight);
int		comprobarVistas(char tablero[4][4],char colUp[4],char coldown[4],char rowLeft[4],char rowRight[4],int posI,int posJ,char candidato);
void 	rascacielosBacktraking(char tablero[4][4],char *colUp, char *coldown, char *rowLeft, char *rowRight,int *solucion,int j,int i);
int 	comprobarVistasSolucion(char tablero[4][4],char colUp[4],char coldown[4],char rowLeft[4],char rowRight[4],int posI,int posJ);
int 	main()
{
	parametros();
	return (0);
}

void parametros()
{
	char	colUp[4] = {"4321"};
	char	coldown[4] = {"1222"};
	char	rowLeft[4] = {"4321"};
	char	rowRight[4] = {"1222"};
	char	tablero[4][4];
	int 	solucion=0;
	int		i;
	int		j;
	printf("colUp[posJ] = %c, coldown = %c, rowleft = %c, rowRight = %c",colUp[0],coldown[0],rowLeft[0],rowRight[0]);
   // printf("colUp[posJ] = %d, coldown = %d, rowleft = %d, rowRight = %d",colUp[0],coldown[0],rowLeft[0],rowRight[0]);
	while (i < 4)
	{
		while (j < 4)
		{
			tablero[i][j] = '0';
			j++;
		}
		printf("\n");
		i++;
	}
	/*while (i < 4)
	{
		colUp[i]=colUp1[i];
		coldown[i]=coldown[i];
		rowLeft[i]=rowLeft1[i];
		rowRight[i]=rowRight1[i];
		i++;
	}*/
	rascacielosBacktraking(tablero, colUp, coldown, rowLeft, rowRight, &solucion, 0, 0);
	while (i < 4)
	{
		while (j < 4)
		{
			printf("%c ", tablero[i][j]);
			j++;
		}
		i++
		printf("\n");
	}
}

void rascacielosBacktraking(char tablero[4][4], char *colUp, char *coldown, char *rowLeft, char *rowRight, int *solucion, int j, int i)
{
	if (esSolucion(tablero, colUp, coldown, rowLeft, rowRight) == 1)
	{
		*solucion = 1;
	}
	else
	{
		char c = '1';
		if (j == 4)
		{
			j = 0;
			i++;
		}
		while (c <= '4' && i < 4 && j < 4)
		{
		   // printf("hola");
			if (aceptable(tablero, colUp, coldown, rowLeft, rowRight, j, i, c) == 1)
			{
				tablero[i][j] = c;
				printf("%c", tablero[i][j]);
				rascacielosBacktraking(tablero, colUp, coldown, rowLeft, rowRight, solucion, j + 1, i);
				if (*solucion == 0)
				{
					tablero[i][j] = '0';
				}
			}
			c++;
		}
	}
}

int	aceptable(char tablero[4][4], char colUp[4], char coldown[4], char rowLeft[4], char rowRight[4], int posJ, int posI, char candidato)
{
	int	i;
	int	j;
	int	correcto;

	i = 0;
	j = 0;
	correcto = 1;
	while (i < 4 && correcto == 1)
	{
		if (tablero[i][posJ] == candidato)
		{
			correcto = 0;
		}
		i++;
	}
	while (j < 4 && correcto == 1)
	{
		if (tablero[posI][j] == candidato)
			correcto = 0;
		j++;
	}
	if (correcto == 1)
	{
		if (comprobarVistas(tablero, colUp, coldown, rowLeft, rowRight, posI, posJ, candidato) == 0)
			correcto = 0;
	}
	printf("%d ", correcto);
	return (correcto);
}
//Comprobarvistas
/*
int comprobarVistas(char tablero[4][4],char colUp[4],char coldown[4],char rowLeft[4],char rowRight[4],int posI,int posJ,char candidato)
{
	int		i=0;
	int		j=0;
	char 	vistaLIzq ='0';
	char 	vistaLDer ='0';
	char	vistaASup ='0';
	char	vistaAInf ='0';
	char	mayor = '0';
	int		correcto = 1;

	tablero[posI][posJ] = candidato;
	while (j <= 3)
	{
		if (mayor < tablero[posI][j] && tablero[posI][j] != 0 )
		{
			vistaLIzq++;
			mayor = tablero[posI][j];
		}
		j++;
	}
	j = 3;
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
	//printf("posI %d, posJ = %d", posI ,posJ);
   // printf("vistaLizq = %c, vistaLDer = %c,  vistaAsup = %c, vistaAinf = %c ",vistaLIzq,vistaLDer,vistaASup,vistaAInf);
  //  printf("colUp[posJ] = %c, coldown = %c, rowleft = %c, rowRight = %c",colUp[posJ],coldown[posJ],rowLeft[posI],rowRight[0]);
	if (posI < 3)
	{
		if ( colUp[posJ] >= vistaASup && coldown[posJ] >= vistaAInf && rowLeft[posI] >= vistaLIzq && rowRight[posI] >= vistaLDer)
		{
			correcto = 1;
		}
		else
		{
			tablero[posI][posJ] = '0';
			correcto = 0;
		}
	}
	if (posI == 3)
	{
		if (colUp[posJ] == vistaASup && coldown[posJ] == vistaAInf && rowLeft[posI] >= vistaLIzq && rowRight[posI] >= vistaLDer)
		{
			correcto = 1;
		}
		else
		{
			tablero[posI][posJ] = '0';
			correcto = 0;
		}
	}
	return (correcto);
}
*/

//Es solucion
/*
int esSolucion(char tablero[4][4],char *colUp, char *coldown, char *rowLeft, char *rowRight)
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
				if (comprobarVistasSolucion(tablero, colUp, coldown, rowLeft, rowRight, i, j) == 0)
					correcto = 0;
			}
			j++;
		}
		i++;
	}
	return (correcto);
}
*/