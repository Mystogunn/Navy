/*
** first_player.c for first_player.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Wed Feb  1 13:34:42 2017 Josselin
** Last update Sun Feb 19 04:47:55 2017 Josselin
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "my.h"

int	first_player(char *filepath)
{
  char	*str;
  pid_t	pid;

  if ((str = malloc(sizeof(char) * 100)) == NULL)
    return (0);
  pid = getpid();
  my_putstr("my_pid: ");
  my_put_nbr(pid);
  my_putstr("\nwaiting for enemy connection...\n\n");
  str = catch_signal();
  if (my_strcmp(str, "error") == 0)
    return (-1);
  str = trad(str);
  my_putstr("enemy connected\n");
  if (algo_player1(filepath, str) == 1)
    return (1);
  return (0);
}
