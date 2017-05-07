/*
** father_delfrsck.c for del_frsck in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/father/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat May  6 22:36:13 2017 Paskal Arzel
** Last update Sat May  6 22:42:25 2017 Paskal Arzel
*/

#include "ftrace.h"

int	del_frsck(ftrace *data)
{
  data->fstack.funcs[data->fstack.insck - 1].name[0] = '\0';
  data->fstack.insck -= 1;
  return (EXIT_SUCCESS);
}
