/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobar_vistas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:19:17 by satienza          #+#    #+#             */
/*   Updated: 2021/07/04 20:33:03 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comprobar_condiciones.h"
int	comprobarVistas(char t[4][4], char input[4][4], int IJ[2], char can)
{
	int		correcto;

	correcto = 1;
	if (can != '0')
		t[IJ[0]][IJ[1]] = can;
	if (IJ[1] == 3)
	{
		correcto = colULt(t, input, IJ);
		if (correcto == 0 && can != '0')
			t[IJ[0]][IJ[1]] = '0';
	}
	if (IJ[0] == 3)
	{
		correcto = filUlt (t, input, IJ);
		if (correcto == 0 && can != '0')
			t[IJ[0]][IJ[1]] = '0';
	}
	return (correcto);
}

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
