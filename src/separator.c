/*
** separator.c for separator in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Apr  4 18:58:43 2017 Paskal Arzel
** Last update Sun May  7 02:27:32 2017 Paskal Arzel
*/

#include "ftrace.h"

int  separator(ftrace *data)
{
  pid_t	pid;

  data->father.pid = getpid();
  if ((pid = fork()) == 0 && pid != -1)
  {
    if (ftrace_son(data) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  }
  else if (pid != -1)
    {
      data->son.pid = pid;
      if (ftrace_father(data) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
