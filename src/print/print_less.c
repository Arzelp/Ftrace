/*
** print_less.c for print_less in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Apr 13 14:32:06 2017 Paskal Arzel
** Last update Wed May  3 22:57:56 2017 Paskal Arzel
*/

#include "ftrace.h"

void vol(void)
{
}

static int print_largs(ftrace *data, int call, t_sys *g_sys, int c)
{
  int i;

  i = 0;
  while (g_sys[call].params[i] != NULL)
  {
    (i == 0) ? c += printf("0x%llx", data->father.regs.rdi) : vol();
    (i == 1) ? c += printf("0x%llx", data->father.regs.rsi) : vol();
    (i == 2) ? c += printf("0x%llx", data->father.regs.rdx) : vol();
    (i == 3) ? c += printf("0x%llx", data->father.regs.rcx) : vol();
    (i == 4) ? c += printf("0x%llx", data->father.regs.r8) : vol();
    (i == 5) ? c += printf("0x%llx", data->father.regs.r9) : vol();
    if (g_sys[call].params[i + 1] != NULL)
	    c += printf(", ");
    i++;
  }
  c += printf(")");
  return (c);
}

static void print_lret(ftrace *data, int call, t_sys *g_sys, int c)
{
  while (c < 38)
  {
    printf(" ");
    c++;
  }
  printf(" ");
  if (strcmp(g_sys[call].retype, "void") == 0)
    {
      printf("= ?");
      return;
    }
  printf("= 0x%llx", data->father.ret_regs.rax);
}

int	print_less(ftrace *data, int call, t_sys *g_sys)
{
  int c;

  c = 0;
  c += printf("%s(", g_sys[call].name);
	c = print_largs(data, call, g_sys, c);
  print_lret(data, call, g_sys, c);
  printf("\n");
  return (EXIT_SUCCESS);
}
