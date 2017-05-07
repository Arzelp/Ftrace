/*
** nm.c for nm in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Feb 16 15:11:54 2017 Paskal Arzel
** Last update Sun May  7 05:28:22 2017 Paskal Arzel
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ftrace.h"

static int	my_nm_elf(t_nm *nm, char *filename)
{
  if (init_nm(nm) == EXIT_FAILURE)
  {
    if (nm->err == true)
	    fprintf(stderr, "nm: %s: no symbols\n", filename);
    else
    	fprintf(stderr, "nm: %s: File format not recognized\n", filename);
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

int	my_nm(ftrace *data, char *filename, int count, int pos)
{
  set_nm_fct(&(data->nm));
  data->nm.multi = false;
  data->nm.ac = count;
  data->nm.i = pos;
  if (filename == NULL || (data->nm.fd = open(filename, O_RDONLY)) == -1)
  {
    fprintf(stderr, "ftrace: %s: No such file\n", filename);
    return (EXIT_FAILURE);
  }
  data->nm.fsize = data->nm.filesize(data->nm.fd);
  if ((data->nm.data = mmap(NULL,
    data->nm.filesize(data->nm.fd),
    PROT_READ, MAP_SHARED, data->nm.fd, 0)) == (void *)-1)
    return (EXIT_FAILURE);
  if (strncmp((char *)data->nm.data + 1, "ELF", 3) == 0)
  {
    if (my_nm_elf(&(data->nm), filename) == EXIT_FAILURE)
      return (EXIT_FAILURE);
    return (set_fct_names(data));
  }
  else
    fprintf(stderr, "ftrace: %s: File format not recognized\n", filename);
  return (EXIT_SUCCESS);
}
