#include <unistd.h>
#include <stdio.h>
#include "comprobar_condiciones.h"
#include "essolucion.h"
#include "comprobar_vistas.h"
int    comprueba_params(int n, char *cond, char params[4][4]);
void    print_table( char tablero[4][4]);
void rascacielosBacktraking(char tablero[4][4], char input[4][4],int *solucion,int IJ[2]);
int aceptable(char tablero[4][4],char input[4][4],int IJ[2],char candidato);

int    main(int args, char **argv)

{
    int        i_j[2];
    char    tablero[4][4];
    int        solucion;
    char    params[4][4];

    i_j[0] = 0;
    i_j[1] = 0;
    solucion = 0;
    if ((!comprueba_params(args, argv[1], params) || argv[1][31] != 0))
    {
        write (1, "Error\n", 6);
        return (0);
    }
;    while (i_j[0] < 4)
    {
        while (i_j[1] < 4)
            tablero[i_j[0]][i_j[1]++] = '0';
        if (i_j[1] == 4)
        {
            i_j[0]++;
            i_j[1]= 0;
        }
    }
	i_j[0] = 0;
    i_j[1] = 0;
    rascacielosBacktraking(tablero, params, &solucion, i_j);
    if (solucion == 0)
        write (1, "Error\n", 6);
    else
        print_table(tablero);
	
}

int    comprueba_params(int n, char *cond, char params[4][4])
{
    int        i;
    int        j;
    int        k;

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

void    print_table( char tablero[4][4])
{
    int        i;
    int        j;

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

void rascacielosBacktraking(char tablero[4][4], char input[4][4],int *solucion,int IJ[2])
{
    if(esSolucion(tablero, input)==1)
    {
        *solucion = 1;
    }
    else
    {
        char c = '1';
        if (IJ[1] == 4)
        {
            IJ[1] = 0;
            IJ[0]++;
        }
        while (c <='4' && IJ[0]<4 && IJ[1]<4)
        {
            if (aceptable(tablero,input, IJ,c)==1)
            {
                tablero[IJ[0]][IJ[1]]=c;
                IJ[1]++;
                rascacielosBacktraking(tablero,input,solucion,IJ);
                if(esSolucion(tablero, input)==0)
                {
					if (IJ[1] > 0)
                    	IJ[1]--;
					else
					{
						IJ[1] = 3;
						IJ[0]--;
					}	
                    tablero[IJ[0]][IJ[1]]='0';		
                }
            }
            c++;
        }
    }
}

int aceptable(char tablero[4][4],char input[4][4],int IJ[2],char candidato)
{
    int i=0;
    int j=0;
    int correcto = 1;
    while (i < 4 && correcto == 1)
    {
        if(tablero[i][IJ[1]]==candidato)
        {
            correcto=0;
        }
        i++;
    }
    while (j <4 && correcto == 1){
        if(tablero[IJ[0]][j]==candidato)
        {
            correcto=0;
        }
        j++;
    }
    if(correcto ==1)
    {
        if (comprobarVistas(tablero,input , IJ, candidato)==0)
            correcto =0;

    }
    return correcto;
}
