/*
** print_time.c for print_time in /home/paskal/rendu/System_Unix/PSU_2016_ftrace/src/print/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu May 4 15:29:07 2017 Paskal Arzel
** Last update Thu May 18 15:30:33 2017 Paskal Arzel
*/

#include "ftrace.h"

int	print_time(void)
{
  time_t	now;
  char		buf[80];
  struct tm ts;

  time(&now);
  ts = *localtime(&now);
  strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
  return (printf("%s ", buf));
}
