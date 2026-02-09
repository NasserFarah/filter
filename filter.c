#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER 100000

void  filter(char *flt)
{
	char	red[BUFFER + 1];
	int	i;
	int	j;
	int	k;
	int	green;
	int	flt_size;

	flt_size = strlen(flt);
	green = 1;
	while (green > 0)
	{
		green = read(0, red, BUFFER);
		red[green] = 0;
		if (green == -1)
		{
			printf("Error: ");
			perror("");
		}
		k = 0;
		j = 0;
		i = 0;
		while (red[i])
		{
			while (flt[j] == red[i + j] && red[i + j] && flt[j])
			{
				while (j == (flt_size - 1) && k <= flt_size - 1 && flt_size > 0)
				{
					red[i + k] = 42;
					k++;
				}
				k = 0;
				j++;
			}
			j = 0;
			i++;
		}
		printf("%s", red);
		printf("\n");
	}
}

int  main(int ac, char **av)
{
	if (ac == 2 && av[1])
	{
		char *flt;
		flt = av[1];
		filter(flt);
	}
	return (1);
}
