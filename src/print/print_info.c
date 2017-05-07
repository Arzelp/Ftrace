/*
** print_info.c for print_info in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun May  7 18:27:57 2017 Paskal Arzel
** Last update Sun May  7 18:33:41 2017 Paskal Arzel
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
  get_signal(data);
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
