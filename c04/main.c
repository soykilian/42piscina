#include <stdio.h>

int		ft_atoi_base(char *str, char *base);
int main(void)
{
	char *base = "mavi";
	char *str = "vviam";

	printf("%d", ft_atoi_base(str, base));
	return (0);
}

