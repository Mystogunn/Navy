/*
** main.c for main.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
** 
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
** 
** Started on  Wed Feb  1 12:08:39 2017 Josselin
** Last update Fri Feb 10 20:01:31 2017 Josselin
*/

#include "my.h"

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      if (check_pos(av[1]) == -1)
	return (84);
      if (first_player(av[1]) == 1)
	return (1);
    }
  else if (ac == 3)
    {
      if (check_pos(av[2]) == -1)
	return (84);
      if (second_player(av) == 1)
	return (1);
    }
  else
    return (84);
  return (0);
}
