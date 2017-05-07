/*
** print_an_arg.c for print_an_arg in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Apr 13 15:23:23 2017 Paskal Arzel
** Last update Wed May  3 22:57:59 2017 Paskal Arzel
*/

#include "ftrace.h"

int	print_int(ftrace *data, int i)
{
  int c;

  c = 0;
  (i == 0) ? c += printf("%d", (int)(data->father.regs.rdi)) : vol();
  (i == 1) ? c += printf("%d", (int)(data->father.regs.rsi)) : vol();
  (i == 2) ? c += printf("%d", (int)(data->father.regs.rdx)) : vol();
  (i == 3) ? c += printf("%d", (int)(data->father.regs.rcx)) : vol();
  (i == 4) ? c += printf("%d", (int)(data->father.regs.r8)) : vol();
  (i == 5) ? c += printf("%d", (int)(data->father.regs.r9)) : vol();
  (i == 6) ? c += printf("%d", (int)(data->father.ret_regs.rax)) : vol();
  return (c);
}

int print_uint(ftrace *data, int i)
{
  int c;

  c = 0;
  (i == 0) ? c += printf("%u", (unsigned int)(data->father.regs.rdi)) : vol();
  (i == 1) ? c += printf("%u", (unsigned int)(data->father.regs.rsi)) : vol();
  (i == 2) ? c += printf("%u", (unsigned int)(data->father.regs.rdx)) : vol();
  (i == 3) ? c += printf("%u", (unsigned int)(data->father.regs.rcx)) : vol();
  (i == 4) ? c += printf("%u", (unsigned int)(data->father.regs.r8)) : vol();
  (i == 5) ? c += printf("%u", (unsigned int)(data->father.regs.r9)) : vol();
  (i == 6) ?
  c += printf("%u", (unsigned int)(data->father.ret_regs.rax)) : vol();
  return (c);
}

int print_long(ftrace *data, int i)
{
  int c;

  c = 0;
  (i == 0) ? c += printf("%ld", (long)(data->father.regs.rdi)) : vol();
  (i == 1) ? c += printf("%ld", (long)(data->father.regs.rsi)) : vol();
  (i == 2) ? c += printf("%ld", (long)(data->father.regs.rdx)) : vol();
  (i == 3) ? c += printf("%ld", (long)(data->father.regs.rcx)) : vol();
  (i == 4) ? c += printf("%ld", (long)(data->father.regs.r8)) : vol();
  (i == 5) ? c += printf("%ld", (long)(data->father.regs.r9)) : vol();
  (i == 6) ? c += printf("%ld", (long)(data->father.ret_regs.rax)) : vol();
  return (c);
}

int print_ulong(ftrace *data, int i)
{
  int c;

  c = 0;
  (i == 0) ?
  c += printf("%lu", (unsigned long)(data->father.regs.rdi)) : vol();
  (i == 1) ?
  c += printf("%lu", (unsigned long)(data->father.regs.rsi)) : vol();
  (i == 2) ?
  c += printf("%lu", (unsigned long)(data->father.regs.rdx)) : vol();
  (i == 3) ?
  c += printf("%lu", (unsigned long)(data->father.regs.rcx)) : vol();
  (i == 4) ? c += printf("%lu", (unsigned long)(data->father.regs.r8)) : vol();
  (i == 5) ? c += printf("%lu", (unsigned long)(data->father.regs.r9)) : vol();
  (i == 6) ?
  c += printf("%lu", (unsigned long)(data->father.ret_regs.rax)) : vol();
  return (c);
}

int print_hexa(ftrace *data, int i)
{
  int c;

  c = 0;
  (i == 0) ? c += printf("%llx", data->father.regs.rdi) : vol();
  (i == 1) ? c += printf("%llx", data->father.regs.rsi) : vol();
  (i == 2) ? c += printf("%llx", data->father.regs.rdx) : vol();
  (i == 3) ? c += printf("%llx", data->father.regs.rcx) : vol();
  (i == 4) ? c += printf("%llx", data->father.regs.r8) : vol();
  (i == 5) ? c += printf("%llx", data->father.regs.r9) : vol();
  (i == 6) ? c += printf("%llx", data->father.ret_regs.rax) : vol();
  return (c);
}
