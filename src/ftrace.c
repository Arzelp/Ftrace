/*
** ftrace.c for ftrace in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Apr  4 17:55:49 2017 Paskal Arzel
** Last update Sun May  7 18:43:37 2017 Paskal Arzel
*/

#include "ftrace.h"

int main(int ac, char **av, char **ae)
{
  ftrace  data;

  if (ac == 1 || !strcmp(av[1], "-h"))
  {
    printf("./ftrace [-s] [-m] [binary]\n");
    printf("    -s : Advanced informations\n    -m : Mute\n");
    return (EXIT_FAILURE);
  }
  if (parser(ac, av, &data) == EXIT_FAILURE
  || init_ftrace(&data, ac, av, ae) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (separator(&data) == EXIT_FAILURE)
  	return (EXIT_FAILURE);
  if (data.working)
    printf("+++ exited with %d +++\n", data.father.ret_value);
  return (EXIT_SUCCESS);
}
