/*
** find_fct.c for find_fct in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Apr 13 23:49:46 2017 Paskal Arzel
** Last update Wed May  3 22:57:49 2017 Paskal Arzel
*/

#include "ftrace.h"

static fct fcts[] =
{
  {"char *"},
  {"const char *"},
  {"int"},
  {"unsigned int"},
  {"long"},
  {"unsigned long"},
  {NULL}
};

int	find_fct(char *type)
{
  int i;

  i = 0;
  while (fcts[i].name != NULL)
  {
    if (strcmp(fcts[i].name, type) == 0)
      return (i);
    i++;
  }
  return (i);
}
