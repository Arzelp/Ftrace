/*
** set_base.c for set_base in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/init/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Feb 22 12:00:15 2017 Paskal Arzel
** Last update Sat May  6 16:42:12 2017 Paskal Arzel
*/

#include "ftrace.h"

int	set_base(t_nm *nm)
{
  nm->pos = 8;
  nm->start_data = nm->data;
  if ((nm->lgnm = malloc(sizeof(t_longname))) == NULL)
    return (EXIT_FAILURE);
  nm->lgnm->start_longname = NULL;
  nm->lgnm->size = 0;
  return (EXIT_SUCCESS);
}
