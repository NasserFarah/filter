#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
        static char     buff[BUFFER_SIZE + 1] = "";
        static char     *line;
        static int      index = 0;
        static int      bytes = 0;
        int             i = 0;
        line = malloc(40000);
        if (!line)
                return (perror("Error"), NULL);
        while (1)
        {
                if (bytes <= index)
                {
                        bytes = read(fd, buff, BUFFER_SIZE);
			index = 0;
                        if (bytes <= 0)
				break ;
                        buff[bytes] = 0;
                }
                line[i] = buff[index];
                i++;
                index++;
                if (buff[index - 1] == '\n')
                        break;
        }
        line[i] = 0;
        if (i == 0)
                return (free(line), NULL);
        return (line);
}

int	main(int ac, char **av)
{
	ssize_t	i = 0;
	size_t	j = 0;
	size_t	k = 0;
	char	*line;
	if (!av[1] || strlen(av[1]) == 0)
		return (1);
	while (ac == 2 && av[1] != NULL && av[1])
	{
		line = get_next_line(0);
		if (!line)
			break;
		while (line[i] != 0)
		{
			if (av[1][j] == line[i])
			{
				while (av[1][j] != 0 && av[1][j] == line[i] && line[i] != 0)
				{
					j++;
					if (j == (strlen(av[1])))
					{
						while (k < j)
						{
							printf("*");
							k++;
							i++;
						}
						i = i - 1;
						k = 0;
					}
				}
			}
			else
				printf("%c", line[i]);
			j = 0;
			i++;
		}
		i = 0;
		j = 0;
		k = 0;
	}
	return (1);
}
