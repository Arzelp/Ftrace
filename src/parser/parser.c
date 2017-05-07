/*
** parser.c for parser in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/parser/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Apr  4 18:00:36 2017 Paskal Arzel
** Last update Sun May  7 18:14:27 2017 Paskal Arzel
*/

#include "ftrace.h"

static void	init_flags(ftrace *data)
{
  data->opt.s = false;
  data->opt.p = false;
  data->opt.m = false;
}

static int	set_in_data(int ac, char **av, ftrace *data, int i)
{
  if (strcmp(av[i], "-s") == 0)
    data->opt.s = true;
  else if (strcmp(av[i], "-m") == 0)
    data->opt.m = true;
  else if (strcmp(av[i], "-p") == 0 && i < ac - 1)
    {
      data->opt.p = true;
      data->solo.pid = atoi(av[i + 1]);
      if ((data->process.name = strdup(av[i + 1])) == NULL)
        return (EXIT_FAILURE);
    }
  else if (data->process.args_pos == -1 && av[i][0] != '-')
    {
      if ((data->process.binary = strdup(av[i])) == NULL)
        return (EXIT_FAILURE);
      data->process.args_pos = i;
    }
  else if (av[i][0] == '-')
    {
      printf("Invalid argument [%s]\n", av[i]);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int  parser(int ac, char **av, ftrace *data)
{
  int  i;

  i = 1;
  init_flags(data);
  data->process.args_pos = -1;
  while (i < ac)
  {
    if (set_in_data(ac, av, data, i) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
    i++;
  }
  return (EXIT_SUCCESS);
}
