int	comprueba_params(char *cond, char params[4][4])
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 1;
	while (i++ < 30)
	{
		if ((cond[i] > 48 && cond[i] < 53) && (i % 2 == 0))
		{
			params[k - 1][j] = cond[i];
			j++;
			if (j % 4 == 0)
			{
				j = 0;
				k++;
			}
		}
		else if (i % 2 != 0 && cond[i] == 32)
			continue ;
		else
			return (0);
	}
	return (1);
}

void	fill_table(char tablero[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
			tablero[i][j++] = '0';
		if (j == 4)
		{
			i++;
			j = 0;
		}
	}
}
