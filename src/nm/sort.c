/*
** sort.c for sort in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Fri Feb 17 15:51:37 2017 Paskal Arzel
** Last update Sat May  6 16:44:48 2017 Paskal Arzel
*/

#include "ftrace.h"

static char	*nb_under(char *str)
{
  int		i;
  bool	done;

  i = 0;
  done = false;
  while (str[i] && str[i] == '_' && !done)
  i++;
  return ((char *)(str + i));
}

static int nbunder(char *str)
{
  int		i;
  bool	done;

  i = 0;
  done = false;
  while (str[i] && str[i] == '_' && !done)
  i++;
  return (i);
}

static int	spestrcmp(char *s1, char *s2)
{
  int		i;
  char	c1;
  char	c2;

  i = 0;
  while (s1[i] && s2[i])
  {
    c1 = (s1[i] <= 'Z' && s1[i] >= 'A') ? s1[i] + 32 : s1[i];
    c2 = (s2[i] <= 'Z' && s2[i] >= 'A') ? s2[i] + 32 : s2[i];
    c1 = (c1 == '_') ? 127 : c1;
    c2 = (c2 == '_') ? 127 : c2;
    if (c2 != c1)
	    return (c1 - c2);
    i++;
  }
  if (s1[i])
    return (1);
  else if (s2[i])
    return (-1);
  return (0);
}

static void	go_check(t_nm *nm, int i)
{
  Elf64_Sym	tmp;

  if (spestrcmp(
    nb_under((char *)&nm->sym.sym_names[nm->sym.symtab[i].st_name]),
    nb_under((char *)&nm->sym.sym_names[nm->sym.symtab[i + 1].st_name]))
    > 0)
    {
      tmp = nm->sym.symtab[i];
      nm->sym.symtab[i] = nm->sym.symtab[i + 1];
      nm->sym.symtab[i + 1] = tmp;
    }
  else if (spestrcmp(
		nb_under((char *)&nm->sym.sym_names[nm->sym.symtab[i].st_name]),
    nb_under((char *)&nm->sym.sym_names[nm->sym.symtab[i + 1].st_name]))
    == 0)
    {
      if (nbunder((char *)&nm->sym.sym_names[nm->sym.symtab[i].st_name]) <
	      nbunder((char *)&nm->sym.sym_names[nm->sym.symtab[i + 1].st_name]))
      {
        tmp = nm->sym.symtab[i];
        nm->sym.symtab[i] = nm->sym.symtab[i + 1];
        nm->sym.symtab[i + 1] = tmp;
      }
    }
}

void				sort_sym_tab(t_nm *nm, int nb_sym)
{
  int		i;
  int		j;

  j = 0;
  while (j < nb_sym)
  {
    i = 0;
    while (i < nb_sym - 1)
    {
      go_check(nm, i);
      i++;
    }
    j++;
  }
}
