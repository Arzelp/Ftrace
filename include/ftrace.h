/*
** ftrace.h for ftrace in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/include/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Apr  4 16:39:54 2017 Paskal Arzel
** Last update Sun May  7 04:15:56 2017 Paskal Arzel
*/

#ifndef ftrace_H__
#define ftrace_H__

#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAXP 9
#define NB_PRINTER 7
#define EXIT_NOPEN 10
#define ARCH_NAME_MAXSIZE 16
#define ARCH_TRASH 32
#define ARCH_SIZE 10
#define ARCH_END 2

typedef struct
{
  bool  s;
  bool  p;
  bool	nobinary;
}flags;

typedef struct
{
  pid_t pid;
  int		args_pos;
  char  *name;
  char	*binary;
  char	**args;
  char	**env;
}proc;

typedef struct
{
  pid_t	pid;
}son;

typedef struct s_sym
{
  char					*sym_names;
  Elf64_Shdr		*symshdr;
  Elf64_Shdr		*strtab;
  Elf64_Sym			*symtb;
  Elf64_Sym			*symtab;
  int						sym_nb;
}t_sym;

typedef struct s_arch_header
{
  char					name[ARCH_NAME_MAXSIZE];
  char					trash[ARCH_TRASH];
  char					size[ARCH_SIZE];
  char					end[ARCH_END];
}t_arch_header;

typedef struct s_longname
{
  char				*start_longname;
  int					size;
}t_longname;

typedef struct s_nm
{
  bool					multi;
  bool					err;
  int						i;
  int						ac;
  int					  pos;
  char					*start_data;
  char					*data;
  char					*sct_names;
  t_arch_header	*arch_header;
  Elf64_Ehdr		*elf;
  Elf64_Shdr		*shdr;
  Elf64_Phdr		*phdr;
  Elf64_Shdr		*dynshdr;
  Elf64_Shdr		*dynstr;
  Elf64_Sym			*dyntb;
  Elf64_Sym			*dyntab;
  Elf64_Addr		pltaddr;
  char					*dyn_names;
  int						fd;
  int						fsize;
  int						dyn_nb;
  t_sym					sym;
  t_longname		*lgnm;
  int						(*filesize)(int);
  int						(*init_longname)(struct s_nm *);
  int						(*find_sym_idxs)(struct s_nm *);
  int						(*get_sym_nb)(struct s_nm *);
  int						(*nm_arch)(struct s_nm *, char *);
  void					(*print_sh_name)(struct s_nm *);
  void					(*print_file_name)(struct s_nm *);
  void					(*print_sym_name)(struct s_nm *);
  void					(*sort_sym_tab)(struct s_nm *, int);
}t_nm;

typedef struct s_fct
{
  char *name;
}fct;

typedef struct s_sys
{
  int		nb;
  char	*name;
  char  *retype;
  char	*params[MAXP];
}t_sys;

typedef struct
{
  struct user_regs_struct regs;
  long										instruction;
}call;

typedef struct
{
  pid_t										pid;
  int											son_status;
  struct user_regs_struct	regs;
  struct user_regs_struct ret_regs;
}fat;

typedef struct s_solo
{
  pid_t		pid;
  int			status;
}sol;

typedef struct s_func
{
  char									*name;
  unsigned long long		value;
}t_func;

typedef struct s_finfo
{
  char								*name;
  long								instruction;
  unsigned long long	value;
}finfo;

typedef struct s_sck
{
  finfo	*funcs;
  int		insck;
  int		maxsize;
  int		maxfuncsize;
}sck;

typedef struct s_trace
{
  flags  opt;
  proc   process;
  son		 son;
  fat		 father;
  sol    solo;
  call   infos;
  t_nm	 nm;
  t_func *func;
  sck		 fstack;
}ftrace;

int   parser(int, char **, ftrace *);
int   init_ftrace(ftrace *, int, char **, char **);
int   separator(ftrace *);
int	  solo(ftrace *data);
int   ftrace_father(ftrace *);
int   print_infos(ftrace *);
void  vol(void);
int   ftrace_son(ftrace *);
int	  print_less(ftrace *, int, t_sys *);
int	  print_full(ftrace *, int, t_sys *);
int	  print_int(ftrace *data, int i);
int	  print_uint(ftrace *data, int i);
int	  print_long(ftrace *data, int i);
int	  print_ulong(ftrace *data, int i);
int	  print_string(ftrace *data, int i);
int   print_hexa(ftrace *data, int i);
int	  find_fct(char *type);
int	  my_nm(ftrace *data, char *filename, int count, int pos);
int		init_nm(t_nm *nm);
void	print_sh_name(t_nm *nm);
void	print_sym_name(t_nm *nm);
int		set_base(t_nm *nm);
void	print_file_name(t_nm *nm);
int		find_sym_idxs(t_nm *nm);
int		get_sym_nb(t_nm *nm);
void	set_nm_fct(t_nm *nm);
int		set_fct_names(ftrace *data);
int		init_longname(t_nm *nm);
void	sort_sym_tab(t_nm *nm, int nb);
int		nm_arch(t_nm *nm, char *filename);
int		set_insck(ftrace *data, char *funcname, int value);
int		del_frsck(ftrace *data);
void	get_dyn_data(ftrace *data);
int		init_dyn(t_nm *nm);
int		find_dyn(ftrace *data);

#endif
