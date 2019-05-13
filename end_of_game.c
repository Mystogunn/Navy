/*
** check_coord.c for check_coord.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sun Feb  5 13:01:46 2017 Josselin
** Last update Fri Feb 17 19:01:16 2017 Josselin
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	end_of_game2(char **map, char **map_enemy)
{
  int	i;
  int	j;
  int   a;

  a = 0;
  j = 0;
  i = 0;
  while (map_enemy[j] != NULL)
    {
      while (map_enemy[j][i++] != 0)
	{
	  if (map_enemy[j][i] == 'x')
	    a = a + 1;
	}
      j = j + 1;
      i = 0;
    }
  if (a == 14)
    {
      write(1, "\n", 1);
      all_print_map(map, map_enemy);
      my_putstr("I won\n");
      return (0);
    }
  return (-1);
}

int	end_of_game(char **map, char **map_enemy)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  while (map[j] != NULL)
    {
      while (map[j][i] != 0)
	{
	  if (map[j][i] > 48 && map[j][i] < 57)
	    return (-1);
	  i = i + 1;
	}
      j = j + 1;
      i = 1;
    }
  all_print_map(map, map_enemy);
  my_putstr("Enemy won\n");
  return (1);
}
