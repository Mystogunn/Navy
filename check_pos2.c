/*
** check_pos2.c for check_pos2.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sat Feb 11 01:54:46 2017 Josselin
** Last update Sun Feb 19 04:52:22 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

int	coord_of_map5(char **map)
{
  int	i;
  int	j;
  int	a;

  a = 0;
  j = 2;
  i = 2;
  while (map[i] != NULL)
    {
      while (map[i][j] != 0)
	{
	  if (map[i][j] != '.')
	    a = a + 1;
	  j = j + 2;
	}
      j = 2;
      i = i + 1;
    }
  if (a != 14)
    return (-1);
  return (0);
}

char	**coord_of_map4(char **coord, int i)
{
  int	a;

  while (coord[i] != NULL)
    {
      if (coord[i][2] == coord[i][5])
	{
	  if (coord[i][3] < coord[i][6])
	    {
	      a = coord[i][3];
	      coord[i][3] = coord[i][6];
	      coord[i][6] = a;
	    }
	}
      if (coord[i][3] == coord[i][6])
	{
	  if (coord[i][2] < coord[i][5])
	    {
	      a = coord[i][2];
	      coord[i][2] = coord[i][5];
	      coord[i][5] = a;
	    }
	}
      i = i + 1;
    }
  return (coord);
}
