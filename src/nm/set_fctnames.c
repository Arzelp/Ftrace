/*
** set_fctnames.c for set_fctnames in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat May  6 16:49:16 2017 Paskal Arzel
** Last update Sun May  7 05:25:29 2017 Paskal Arzel
*/

#include "ftrace.h"

static int	get_nb_func(ftrace *data)
{
  int	i;
  int	len;

  len = 0;
  i = 0;
  while (i < data->nm.sym.sym_nb)
  {
    if (data->nm.sym.symtab[i].st_value != 0 &&
	    strcmp(&(data->nm.sym.sym_names
        [data->nm.sym.symtab[i].st_name]), "") != 0)
	    len++;
    else if (data->nm.sym.symtab[i].st_shndx == SHN_UNDEF &&
    strcmp(&(data->nm.sym.sym_names[data->nm.sym.symtab[i].st_name]), "") != 0
    && ELF64_ST_BIND(data->nm.sym.symtab[i].st_info) != STB_WEAK)
      len++;
    i++;
  }
  return (len);
}

static int	set_one_func(ftrace *data, int i, int j)
{
  if ((data->func[j].name = malloc((strlen(&(data->nm.sym.sym_names
      [data->nm.sym.symtab[i].st_name]))
    + 1) * sizeof(char))) == NULL)
    return (EXIT_FAILURE);
  if (strcpy(data->func[j].name,
    &(data->nm.sym.sym_names[data->nm.sym.symtab[i].st_name])) == NULL)
    return (EXIT_FAILURE);
  data->func[j].value = data->nm.sym.symtab[i].st_value;
  return (EXIT_SUCCESS);
}

static int	calc_maxsize(ftrace *data)
{
  size_t maxlen;
  int i;

  i = 0;
  maxlen = 0;
  while (data->func[i].name != NULL)
  {
    if (strlen(data->func[i].name) > maxlen)
	    maxlen = strlen(data->func[i].name);
    i++;
  }
  return (maxlen + 2);
}

int	set_fct_names(ftrace *data)
{
  int	len;
  int	i;
  int	j;

  len = get_nb_func(data);
  i = 0;
  if ((data->func = malloc((len + 1) * sizeof(t_func))) == NULL)
    return (EXIT_FAILURE);
  if ((j = find_dyn(data)) == -1)
    return (EXIT_FAILURE);
  while (i < data->nm.sym.sym_nb && j < len)
  {
    if (data->nm.sym.symtab[i].st_value != 0 &&
	    strcmp(&(data->nm.sym.sym_names
        [data->nm.sym.symtab[i].st_name]), "") != 0)
    {
      if (set_one_func(data, i, j) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
      j++;
    }
    i++;
  }
  data->func[j].name = NULL;
  data->fstack.maxfuncsize = calc_maxsize(data);
  return (EXIT_SUCCESS);
}
