//
// Created by Sergio Atienza pastor on 7/4/21.
//

#ifndef COMPROBAR_VISTAS_H
# define COMPROBAR_VISTAS_H
int		comprobarVistas(char t[4][4], char input[4][4], int IJ[2], char can);
char	vista_fila_izquierda(char tablero[4][4], int posI);
char	vista_fila_derecha(char tablero[4][4], int posI);
char	vista_col_superior(char tab[4][4], int posJ);
char	vista_col_inferior(char tablero[4][4], int posJ);
#endif 
