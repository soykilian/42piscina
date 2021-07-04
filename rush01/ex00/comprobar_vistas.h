/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobar_vistas.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satienza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:19:17 by satienza          #+#    #+#             */
/*   Updated: 2021/07/04 10:27:54 by satienza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comprobarVistas(char tablero[4][4], char colUp[4], char coldown[4], 
		char rowLeft[4], char rowRight[4], int posI,int posJ, char candidato)
{
	int		i;
	int		j;
	char	vistaLIzq;
	char 	vistaLDer;
	char	vistaASup;
	char	vistaAInf;
	char	mayor;
	int		correcto;

	i = 0;
	vistaLIzq = '0';
	vistaLDer = '0';
	vistaASup = '0';
	visaAInf = '0';
	mator = '0';
	corrector = 1;
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
		if (mayor < tablero[i][posJ] && tablero[i][posJ] != 0)
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
	if (posJ == 3)
	{
		if (rowLeft[posI] == vistaLIzq && rowRight[posI] == vistaLDer)
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
		if (colUp[posJ] == vistaASup && coldown[posJ] == vistaAInf)
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
