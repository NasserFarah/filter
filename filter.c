#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void  filter(char *flt);

int  main(int ac, char **av)
{
  if (ac == 2)
  {
    filter(av[1]);
  }
  return (1);
}
