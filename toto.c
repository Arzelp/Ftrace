#include <stdio.h>
#include <stdlib.h>

int my_putchar(char c)
{
  return (write(1, &c, 1));
}

int my_putstr(char *str)
{
  int  i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}

int my_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int main(int ac, char **av)
{
  int toto;
  int lim;
  int to;
  int t;

  if (ac < 3)
    return (1);
  lim = atoi(av[1]);
  if (lim <= 0)
    return (1);
  toto = 0;
  while (toto < lim)
    {
      to = my_strlen(av[2]);
      my_putstr("Je print :D : ");
      my_putstr(av[2]);
      t = 0;
      while (t < toto)
	{
	  printf("J'AI PRINT UN TRUC OMG\n");
	  t++;
	}
      toto++;
    }
  return (1);
}
