/*
** init.c for init in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/init/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Apr  4 18:16:13 2017 Paskal Arzel
** Last update Sun May  7 02:27:36 2017 Paskal Arzel
*/

#include "ftrace.h"

static int	init_proc(ftrace *data, int ac, char **av, char **ae)
{
  int	i;

  i = data->process.args_pos;
  data->process.pid = 0;
  data->process.name = NULL;
  data->process.env = ae;
  data->opt.nobinary = true;
  if ((data->process.args = malloc((ac + 1) * sizeof(char *))) == NULL)
    return (EXIT_FAILURE);
  while (i >= 0 && i < ac)
  {
    if (av[i][0] == '-')
	    i = ac;
    if (i != ac &&
      (data->process.args[i - data->process.args_pos] = strdup(av[i])) == NULL)
    	return (EXIT_FAILURE);
    i++;
  }
  if (i >= 0)
  {
    data->process.args[i - data->process.args_pos] = NULL;
    data->opt.nobinary = false;
  }
  return (EXIT_SUCCESS);
}

static void	init_son(ftrace *data)
{
  data->son.pid = 0;
}

static int	init_sck(ftrace *data)
{
  if ((data->fstack.funcs = malloc(2 * sizeof(finfo))) == NULL)
    return (EXIT_FAILURE);
  if ((data->fstack.funcs[0].name =
       malloc(data->fstack.maxfuncsize * sizeof(char))) == NULL)
    return (EXIT_FAILURE);
  strcpy(data->fstack.funcs[0].name, "");
  data->fstack.funcs[1].name = NULL;
  data->fstack.funcs[0].instruction = -1;
  data->fstack.maxsize = 1;
  data->fstack.insck = 0;
  return (EXIT_SUCCESS);
}

int  				init_ftrace(ftrace *data, int ac, char **av, char **ae)
{
  my_nm(data, data->process.binary, 1, 0);
  if (init_sck(data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  init_son(data);
  if (init_proc(data, ac, av, ae) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
