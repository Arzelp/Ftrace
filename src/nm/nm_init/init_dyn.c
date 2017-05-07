/*
** init_dyn.c for init_dun in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/nm/nm_init/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun May  7 01:00:45 2017 Paskal Arzel
** Last update Sun May  7 04:32:34 2017 Paskal Arzel
*/

#include "ftrace.h"

static int		get_dyn_nb(t_nm *nm)
{
  return (nm->dynshdr->sh_size / sizeof(Elf64_Dyn));
}

static int	set_dynames(t_nm *nm)
{
  nm->dyntb = (Elf64_Sym *)(nm->data + nm->dynshdr->sh_offset);
  if ((nm->dyntab = malloc(nm->dynshdr->sh_size + 1)) == NULL)
  {
    nm->err = true;
    return (EXIT_FAILURE);
  }
  nm->dyntab = memcpy(nm->dyntab,
    nm->dyntb, nm->dynshdr->sh_size);
  nm->dyn_names = (char *)(nm->data + nm->dynstr->sh_offset);
  if ((nm->dyn_nb = get_dyn_nb(nm)) < 0)
  {
    nm->err = true;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

int	init_dyn(t_nm *nm)
{
  int	i;

  i = -1;
  while (++i < nm->elf->e_shnum - 3)
  {
    if (nm->shdr[i].sh_type == SHT_DYNSYM)
      nm->dynshdr = ((Elf64_Shdr *)&(nm->shdr[i]));
    else if (!strcmp(&nm->sct_names[nm->shdr[i].sh_name], ".plt"))
      nm->pltaddr = nm->shdr[i].sh_addr;
    else if (!strcmp(&nm->sct_names[nm->shdr[i].sh_name], ".dynstr"))
      nm->dynstr = ((Elf64_Shdr *)&(nm->shdr[i]));
  }
  if (set_dynames(nm) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
