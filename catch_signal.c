/*
** catch_signal.c for catch_signal.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Fri Feb  3 16:25:46 2017 Josselin
** Last update Sun Feb 19 21:11:33 2017 Josselin
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char    *g_global;

int     check_global()
{
  int   i;

  i = 0;
  while (g_global[i] != 0)
    {
      if (g_global[i] == '0' && g_global[i + 1] == '0')
	return (-1);
      i = i + 1;
    }
  return (0);
}

void    handler(int signo)
{
  static int    i;

  if (signo == SIGUSR1)
    g_global[i] = '1';
  else
    g_global[i] = '0';
  i = i + 1;
  g_global[i] = 0;
  if (g_global[i - 2] == '0' && g_global[i - 1] == '0')
    i = 0;
}

char	*catch_signal()
{
  if ((g_global = malloc(sizeof(char) * 1000)) == NULL)
    return (NULL);
  while (1)
    {
      if (signal(SIGUSR1, handler) == SIG_ERR)
	return ("error");
      if (signal(SIGUSR2, handler) == SIG_ERR)
	return ("error");
      if (check_global() == -1)
	break;
    }
  return (g_global);
}
