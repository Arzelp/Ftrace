/*
** ftrace_father.c for ftrace_father in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/father/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Apr  4 19:01:53 2017 Paskal Arzel
** Last update Sat May  6 22:43:10 2017 Paskal Arzel
*/

#include "syscall.h"

static bool	check_if_intern(ftrace *data)
{
  int i;

  i = 0;
  while (data->func[i].name != NULL)
  {
    if (data->func[i].value == data->father.regs.rip)
    {
      printf("Entering function %s at 0x%llx\n", data->func[i].name,
      data->func[i].value);
      if (set_insck(data, data->func[i].name, data->func[i].value)
	      == EXIT_FAILURE)
	      return (true);
  	  return (true);
    }
    i++;
  }
  return (false);
}

static bool	check_if_leaving(ftrace *data)
{
  if (data->fstack.insck != 0 &&
    data->fstack.funcs[data->fstack.insck - 1].instruction
    == data->infos.instruction)
    {
      printf("Leaving function %s at 0x%llx\n",
      data->fstack.funcs[data->fstack.insck - 1].name,
      data->fstack.funcs[data->fstack.insck - 1].value);
      if (del_frsck(data) == EXIT_FAILURE)
	      return (true);
    }
  return (false);
}

static int	nosys(ftrace *data)
{
  if (check_if_intern(data) == true)
    return (EXIT_SUCCESS);
  if (check_if_leaving(data) == true)
    return (EXIT_SUCCESS);
  return (EXIT_SUCCESS);
}

int print_infos(ftrace *data)
{
  data->infos.instruction = ptrace(PTRACE_PEEKTEXT,
    data->son.pid, data->father.regs.rsp, 0);
  if (data->father.regs.orig_rax < 329)
  {
    if (data->opt.s)
      return (print_full(data, data->father.regs.orig_rax, g_sys));
    else
	    return (print_less(data, data->father.regs.orig_rax, g_sys));
  }
  else
    return (nosys(data));
  return (EXIT_SUCCESS);
}

int  ftrace_father(ftrace *data)
{
  waitpid(-1, &(data->father.son_status), 0);
  while (WIFSTOPPED(data->father.son_status))
  {
    if (ptrace(PTRACE_GETREGS, data->son.pid, 0, &(data->father.regs)) == -1)
    	return (EXIT_FAILURE);
    if (ptrace(PTRACE_SINGLESTEP, data->son.pid, 0, NULL) == -1)
      return (EXIT_FAILURE);
    if (waitpid(-1, &(data->father.son_status), 0) == -1)
      return (EXIT_FAILURE);
    if (ptrace(PTRACE_GETREGS,
      data->son.pid, 0, &(data->father.ret_regs)) == -1)
      return (EXIT_SUCCESS);
    ptrace(PTRACE_PEEKUSER, data->son.pid, data->father.regs.rdi, NULL);
    print_infos(data);
  }
  return (EXIT_SUCCESS);
}
