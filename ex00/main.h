//
// Created by Sergio Atienza pastor on 7/4/21.
//

#ifndef EX00_MAIN_H
#define EX00_MAIN_H
int comprueba_params(int n, char *cond, char params[4][4]);
void    print_table( char tablero[4][4]);
void rascacielosBacktraking(char tablero[4][4], char input[4][4],int *solucion,int IJ[2]);
int aceptable(char tablero[4][4],char input[4][4],int IJ[2],char candidato);
#endif //EX00_MAIN_H
