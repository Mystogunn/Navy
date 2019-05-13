/*
** second_player.c for second_player.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Wed Feb  1 13:53:18 2017 Josselin
** Last update Sun Feb 19 04:50:43 2017 Josselin
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

int	push_pid(char *str, char *pid)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      usleep(1000);
      if (str[i] == '1')
	{
	  if (kill(my_getnbr(pid), SIGUSR1) == -1)
	    return (-1);
	}
      if (str[i] == '0')
	{
	  if (kill(my_getnbr(pid), SIGUSR2) == -1)
	    return (-1);
	}
      i = i + 1;
    }
  return (0);
}

int	second_player(char **av)
{
  pid_t pid;
  char  *bin_pid;

  pid  = getpid();
  my_putstr("my_pid: ");
  my_put_nbr(pid);
  my_putstr("\n");
  if ((bin_pid = malloc(sizeof(char) * 100)) == NULL)
    return (0);
  bin_pid = crypt_str(convert_nbr(pid));
  if (push_pid(bin_pid, av[1]) == -1)
    return (-1);
  my_putstr("successfully connected\n");
  if (algo_player2(av) == 1)
    return (1);
  return (0);
}
