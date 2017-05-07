/*
** print_full.c for print_full in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Apr 13 15:16:11 2017 Paskal Arzel
** Last update Wed May  3 22:57:53 2017 Paskal Arzel
*/

#include "ftrace.h"

static int	print_arg(ftrace *data, char *type, int i)
{
  int fct_nb;
  int (*printer[NB_PRINTER])(ftrace *, int);

  printer[0] = &print_string;
  printer[1] = &print_string;
  printer[2] = &print_int;
  printer[3] = &print_uint;
  printer[4] = &print_long;
  printer[5] = &print_ulong;
  printer[6] = &print_hexa;
  printer[7] = NULL;
  fct_nb = find_fct(type);
  if (fct_nb < NB_PRINTER)
    return (printer[fct_nb](data, i));
  return (0);
}

static int	print_fargs(ftrace *data, int call, t_sys *g_sys, int c)
{
  int i;

  i = 0;
  while (g_sys[call].params[i] != NULL)
  {
    c += print_arg(data, g_sys[call].params[i], i);
    if (g_sys[call].params[i + 1] != NULL)
	    c += printf(", ");
    i++;
  }
  c += printf(")");
  return (c);
}

static void print_fret(ftrace *data, int call, t_sys *g_sys, int c)
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
  printf("= ");
  print_arg(data, g_sys[call].retype, 6);
}

int	print_full(ftrace *data, int call, t_sys *g_sys)
{
  int c;

  (void)data;
  c = printf("%s(", g_sys[call].name);
  c = print_fargs(data, call, g_sys, c);
  print_fret(data, call, g_sys, c);
  printf("\n");
  return (EXIT_SUCCESS);
}
