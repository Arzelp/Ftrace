/*
** signals.h for signals in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/include/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun May  7 16:05:27 2017 Paskal Arzel
** Last update Sun May  7 16:07:35 2017 Paskal Arzel
*/

#ifndef SIGNALS_H__
#define SIGNALS_H__

#include "ftrace.h"

t_sig g_sig[] =  {
  {"SIGHUP", true},
  {"SIGINT", true},
  {"SIGQUIT", true},
  {"SIGILL", true},
  {"SIGTRAP", true},
  {"SIGABRT", true},
  {"SIGBUS", true},
  {"SIGFPE", true},
  {"SIGKILL", true},
  {"SIGUSR1", true},
  {"SIGSEGV", true},
  {"SIGUSR2", true},
  {"SIGPIPE", true},
  {"SIGALRM", true},
  {"SIGTERM", true},
  {"SIGSTKFLT", true},
  {"SIGCHLD", false},
  {"SIGCONT", false},
  {"SIGSTOP", false},
  {"SIGTSTP", false},
  {"SIGTTIN", false},
  {"SIGTTOU", false},
  {"SIGURG", false},
  {"SIGXCPU", false},
  {"SIGXFSZ", true},
  {"SIGVTALRM", true},
  {"SIGPROF", true},
  {"SIGWINCH", true},
  {"SIGIO", true},
  {"SIGPWR", true},
  {"SIGSYS", true},
  {"SIGRTMIN", false},
  {"SIGRTMAX", false},
};

#endif
