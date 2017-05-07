/*
** print_string.c for print_sring in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Apr 13 15:41:47 2017 Paskal Arzel
** Last update Wed May  3 22:58:03 2017 Paskal Arzel
*/

#include "ftrace.h"

static long get_ptrace(ftrace *data, int i, int k)
{
  long ptrace_res;

  ptrace_res = (i == 0) ? ptrace(PTRACE_PEEKTEXT,
     data->son.pid, data->father.regs.rdi + 4 * k, NULL) : 0;
  ptrace_res = (i == 1) ? ptrace(PTRACE_PEEKTEXT,
     data->son.pid, data->father.regs.rsi + 4 * k, NULL) : ptrace_res;
  ptrace_res = (i == 2) ? ptrace(PTRACE_PEEKTEXT,
     data->son.pid, data->father.regs.rdx + 4 * k, NULL) : ptrace_res;
  ptrace_res = (i == 3) ? ptrace(PTRACE_PEEKTEXT,
     data->son.pid, data->father.regs.rcx + 4 * k, NULL) : ptrace_res;
  ptrace_res = (i == 4) ? ptrace(PTRACE_PEEKTEXT,
     data->son.pid, data->father.regs.r8 + 4 * k, NULL) : ptrace_res;
  ptrace_res = (i == 5) ? ptrace(PTRACE_PEEKTEXT,
     data->son.pid, data->father.regs.r9 + 4 * k, NULL) : ptrace_res;
  return (ptrace_res);
}

static bool print_buf(char tiny_buf[4], int *c)
{
  bool done;
  int j;

  done = false;
  j = 0;
  while (j < 4 && tiny_buf[j] && tiny_buf[j] > 0)
  {
    printf("%c", tiny_buf[j]);
    *c = *c + 1;
    j++;
  }
  if (j < 4)
    done = true;
  return (done);
}

int	print_string(ftrace *data, int i)
{
  int c;
  int k;
  long ptrace_res;
  char tiny_buf[4];
  bool done;

  c = 0;
  printf("\"");
  done = false;
  k = 0;
  while (!done)
  {
    ptrace_res = get_ptrace(data, i, k);
    memmove(tiny_buf, &ptrace_res, sizeof(tiny_buf));
    done = print_buf(tiny_buf, &c);
    k++;
  }
  printf("\"");
  return (c + 2);
}
