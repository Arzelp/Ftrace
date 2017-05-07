/*
** ftrace_father.c for ftrace_father in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/father/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Apr  4 19:01:53 2017 Paskal Arzel
** Last update Sun May  7 18:34:04 2017 Paskal Arzel
*/

#include "ftrace.h"

void	intHandler(int toto)
{
  (void)toto;
  printf("--- SIGINT (Interrupt) ---\n");
  printf("+++ killed by SIGINT +++\n");
  exit(SIGINT);
}

int  ftrace_father(ftrace *data)
{
  signal(SIGINT, intHandler);
  waitpid(-1, &(data->father.son_status), 0);
  while (WIFSTOPPED(data->father.son_status))
  {
    if (ptrace(PTRACE_GETREGS, data->son.pid, 0, &(data->father.regs)) == -1)
    	return (EXIT_FAILURE);
    if (ptrace(PTRACE_SINGLESTEP, data->son.pid, 0, NULL) == -1)
      return (EXIT_FAILURE);
    if (waitpid(-1, &(data->father.son_status), 0) == -1)
      return (EXIT_FAILURE);
    if (ptrace(PTRACE_GETSIGINFO, data->son.pid, 0, &(data->father.sig)) == -1)
      return (false);
    if (ptrace(PTRACE_GETREGS,
      data->son.pid, 0, &(data->father.ret_regs)) == -1)
      return (EXIT_SUCCESS);
    ptrace(PTRACE_PEEKUSER, data->son.pid, data->father.regs.rdi, NULL);
    print_infos(data);
    data->father.ret_value = data->father.regs.rax;
  }
  return (EXIT_SUCCESS);
}
