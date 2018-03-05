/*
** father_signals.c for father_signals in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/father/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun May  7 16:01:16 2017 Paskal Arzel
** Last update Thu May 18 15:37:52 2017 Paskal Arzel
*/

#include "ftrace.h"
#include "signals.h"

bool	get_signal(ftrace *data)
{
  if (data->father.sig.si_signo != SIGTRAP)
  {
    if (g_sig[data->father.sig.si_signo - 1].killer)
    {
      if (data->opt.t)
  	    print_time();
      printf("Received a deadly signal %s\n",
      g_sig[data->father.sig.si_signo - 1].name);
      kill(data->son.pid, data->father.sig.si_signo);
      printf("+++ killed by %s +++\n",
      g_sig[data->father.sig.si_signo - 1].name);
      exit(EXIT_SUCCESS);
    }
    else
    {
      printf("Received signal %s\n",
      g_sig[data->father.sig.si_signo - 1].name);
	    return (true);
    }
  }
  return (false);
}
