/*
** toto.c for toto in /home/paskal/rendu/System_Unix/PSU_2016_ftrace
** 
** Made by Paskal
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat May  6 16:19:57 2017 Paskal
** Last update Sun May  7 18:34:50 2017 Paskal
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}

int	my_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}

int	go_inc(int i)
{
  i = i + 1;
  i *= -1;
  printf("i = %d\n", i);
  return (i);
}

int	go_dec(int i)
{
  i = i - 1;
  i *= -1;
  printf("i = %d\n", i);
  return (i);
}

int main(int ac, char **av)
{
  int i;
  int len;

      i = 0;
  if (ac == 1)
    {
      my_putstr("Wallah y'a pas d'argument wsh !\n");
      return (1);
    }
  if ((i = atoi(av[1])) != 0)
    {
      while (i != 0)
	{
	  if (i < 0)
	    i = go_inc(i);
	  else
	    i = go_dec(i);
	}
    }
  while (i < ac)
    {
      len = my_strlen(av[i]);
      my_putstr("String : ");
      my_putstr(av[i]);
      my_putstr("\n");
      i++;
    }
  return (0);
}
