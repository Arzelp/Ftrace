/*
** father_setinsck.c for setinsck in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/father/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat May  6 20:16:54 2017 Paskal Arzel
** Last update Sat May  6 22:34:52 2017 Paskal Arzel
*/

#include "ftrace.h"

int	set_insck(ftrace *data, char *funcname, int value)
{
  if (data->fstack.insck == data->fstack.maxsize)
    {
      if ((data->fstack.funcs = realloc(data->fstack.funcs,
        (data->fstack.maxsize + 2) * sizeof(finfo))) == NULL)
	      return (EXIT_FAILURE);
      if ((data->fstack.funcs[data->fstack.maxsize].name =
        malloc(data->fstack.maxfuncsize * sizeof(char))) == NULL)
	      return (EXIT_FAILURE);
      data->fstack.maxsize = data->fstack.maxsize + 1;
    }
  strcpy(data->fstack.funcs[data->fstack.insck].name, funcname);
  data->fstack.funcs[data->fstack.insck].instruction = data->infos.instruction;
  data->fstack.funcs[data->fstack.insck].value = value;
  data->fstack.insck = data->fstack.insck + 1;
  return (EXIT_SUCCESS);
}
