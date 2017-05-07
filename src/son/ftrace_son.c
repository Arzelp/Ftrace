/*
** ftrace_son.c for ftrace in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/son/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Apr  4 19:03:50 2017 Paskal Arzel
** Last update Sun May  7 18:13:30 2017 Paskal Arzel
*/

#include "ftrace.h"

static void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
  {
    if (i != 0)
      printf(" ");
    printf("%s", tab[i]);
    if (tab[i + 1] != NULL)
	    printf(",");
    i++;
  }
}

int  ftrace_son(ftrace *data)
{
  data->son.pid = getpid();
  if (data->opt.m)
  {
    if (dup2(3, 1) == -1)
    {
      printf("Can't dup\n");
      return (EXIT_FAILURE);
    }
  }
  if (ptrace(PTRACE_TRACEME, data->son.pid, 0, &(data->infos.regs)) == -1)
    return (EXIT_FAILURE);
  if (data->opt.nobinary)
    {
      printf("no binary detected\n");
      return (EXIT_FAILURE);
    }
  if (execvp(data->process.binary, data->process.args) == -1)
  {
    printf("Can't exec %s with args (", data->process.binary);
    print_tab(data->process.args);
    printf(")...\n");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
