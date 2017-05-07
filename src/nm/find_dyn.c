/*
** find_dyn.c for find_dyn in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat May  6 23:31:05 2017 Paskal Arzel
** Last update Sun May  7 05:26:00 2017 Paskal Arzel
*/

#include "ftrace.h"

static void	set_end(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[i] == '@')
    {
      str[i] = '\0';
      return;
    }
    i++;
  }
}

static int	set_one_dyn(ftrace *data, int i, int j)
{
  if ((data->func[j].name = malloc((strlen(&(data->nm.sym.sym_names
      [data->nm.sym.symtab[i].st_name]))
    + 1) * sizeof(char))) == NULL)
    return (EXIT_FAILURE);
  if (strcpy(data->func[j].name,
    &(data->nm.sym.sym_names[data->nm.sym.symtab[i].st_name])) == NULL)
    return (EXIT_FAILURE);
  data->func[j].value = data->nm.pltaddr + (16 * (j + 1));
  set_end(data->func[j].name);
  return (EXIT_SUCCESS);
}

int	find_dyn(ftrace *data)
{
  int	i;
  int j;

  i = 0;
  j = 0;
  while (i < data->nm.sym.sym_nb)
  {
    if (data->nm.sym.symtab[i].st_shndx == SHN_UNDEF &&
    strcmp(&(data->nm.sym.sym_names[data->nm.sym.symtab[i].st_name]), "") != 0
    && ELF64_ST_BIND(data->nm.sym.symtab[i].st_info) != STB_WEAK)
			{
        if (set_one_dyn(data, i, j) == EXIT_FAILURE)
	        return (-1);
        j++;
      }
    i++;
  }
  return (j);
}
