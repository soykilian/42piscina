#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>

int main(void)
{
	char	ch;
	int		f;

	f = open("cositas", O_CREAT | O_WRONLY | O_TRUNC);

	while(read(STDIN_FILENO, &ch, 1) > 0)
	{
		write(f, &ch, 1);
	}
	write(f, "fin", 3);
	close (f);
}
