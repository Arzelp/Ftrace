/*
** init.c for init in /home/paskal/rendu/System_Unix/PSU_2016_nmobjdump/src/nm/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Feb 16 15:27:53 2017 Paskal Arzel
** Last update Sun May  7 00:58:26 2017 Paskal Arzel
*/

#include "ftrace.h"

static int		filesize(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}

void		set_nm_fct(t_nm *nm)
{
  nm->filesize = &filesize;
  nm->find_sym_idxs = &find_sym_idxs;
  nm->get_sym_nb = &get_sym_nb;
  nm->sort_sym_tab = &sort_sym_tab;
  nm->init_longname = &init_longname;
}

static int		init_ptrs(t_nm	*nm)
{
  nm->elf = (Elf64_Ehdr *)nm->data;
  if ((char *)nm->elf > (char *)(nm->data + nm->fsize))
    return (EXIT_FAILURE);
  nm->shdr = (Elf64_Shdr *)(nm->data + nm->elf->e_shoff);
  if ((char *)nm->shdr > (char *)(nm->data + nm->fsize))
    return (EXIT_FAILURE);
  nm->phdr = (Elf64_Phdr *)(nm->data + nm->elf->e_phoff);
  if ((char *)nm->phdr > (char *)(nm->data + nm->fsize))
    return (EXIT_FAILURE);
  nm->sct_names = (char *)(nm->data + nm->shdr[nm->elf->e_shstrndx].sh_offset);
  if ((char *)nm->sct_names > (char *)(nm->data + nm->fsize))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

static int		init_sym(t_nm *nm)
{
  if (nm->find_sym_idxs(nm) == EXIT_FAILURE)
  {
    nm->err = true;
    return (EXIT_FAILURE);
  }
  nm->sym.symtb = (Elf64_Sym *)(nm->data + nm->sym.symshdr->sh_offset);
  if ((nm->sym.symtab = malloc(nm->sym.symshdr->sh_size + 1)) == NULL)
  {
    nm->err = true;
    return (EXIT_FAILURE);
  }
  nm->sym.symtab = memcpy(nm->sym.symtab,
    nm->sym.symtb, nm->sym.symshdr->sh_size);
  nm->sym.sym_names = (char *)(nm->data + nm->sym.strtab->sh_offset);
  if ((nm->sym.sym_nb = nm->get_sym_nb(nm)) < 0)
  {
    nm->err = true;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

int						init_nm(t_nm *nm)
{
  nm->err = false;
  if (init_ptrs(nm) == EXIT_FAILURE)
  {
    printf("init_ptrs failed\n");
    return (EXIT_FAILURE);
  }
  if (init_sym(nm) == EXIT_FAILURE)
  {
    printf("init_sym failed\n");
    return (EXIT_FAILURE);
  }
  if (init_dyn(nm) == EXIT_FAILURE)
  {
    printf("init_dyn failed\n");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
