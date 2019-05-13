/*
** check_pos.c for check_pos.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Fri Feb 10 18:33:30 2017 Josselin
** Last update Sun Feb 19 04:52:32 2017 Josselin
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int	coord_of_map3(char **coord)
{
  int	i;

  i = 0;
  coord = coord_of_map4(coord, i);
  while (coord[i] != NULL)
    {
      if (coord[i][2] == coord[i][5])
	{
	  if (coord[i][0] - 48 != (coord[i][3] - coord[i][6]) + 1)
	    return (-1);
	}
      if (coord[i][3] == coord[i][6])
	{
	  if (coord[i][0] - 48 != (coord[i][2] - coord[i][5]) + 1)
	    return (-1);
	}
      i = i + 1;
    }
  return (0);
}

int	coord_of_map2(char **coord)
{
  int	i;
  int	a;

  a = 0;
  i = 0;
  while (coord[i] != NULL)
    {
      if (coord[i][3] < 49 || (coord[i][3] > 56 && coord[i][3] < 65)
	  || coord[i][3] > 72 || coord[i][5] < 49 || (coord[i][5] > 56
	  && coord[i][5] < 65) || coord[i][5] > 72 || coord[i][6] < 49
	  || (coord[i][6] > 56 && coord[i][6] < 65) || coord[i][6] > 72
	  || (coord[i][2] > 48 && coord[i][2] < 57 && coord[i][3] > 48
	  && coord[i][3] < 57) || (coord[i][2] > 64 && coord[i][2] < 73
	  && coord[i][3] > 64 && coord[i][3] < 73) || (coord[i][5] > 48
	  && coord[i][5] < 57 && coord[i][6] > 48 && coord[i][6] < 57)
	  || (coord[i][5] > 64 && coord[i][5] < 73 && coord[i][6] > 64
	  && coord[i][6] < 73))
	return (-1);
      a = coord[i][0] + a;
      i = i + 1;
    }
  if (a != 206)
    return (-1);
  return (0);
}

char	**convert_for_check(char **coord)
{
  int	i;
  int	j;

  i = 0;
  while (coord[i] != NULL)
    {
      j = 0;
      while (coord[i][j] != 0)
	{
	  if (coord[i][j] > 96 && coord[i][j] < 105)
	    coord[i][j] = coord[i][j] - 32;
	  j = j + 1;
	}
	  i = i + 1;
    }
  return (coord);
}

int     coord_of_map(char **coord)
{
  int   i;
  int	j;
  int	a;

  a = 0;
  j = 0;
  i = 0;
  while (coord[i] != NULL)
    {
      if (coord[i][1] != ':' || coord[i][4] != ':' || coord[i][0] < '2'
	  || coord[i][0] > '5' || (coord[i][2] != coord[i][5]
	  && coord[i][3] != coord[i][6]) || coord[i][2] < 49
	  || (coord[i][2] > 56 && coord[i][2] < 65) || coord[i][2] > 72)
	return (-1);
      while (coord[i][a++] != 0)
	j = j + 1;
      a = 0;
      i = i + 1;
    }
  if (j != 28)
    return (-1);
  return (0);
}

int	check_pos(char *pos)
{
  char	**coord;
  char	**map;

  coord = convert_tab(pos);
  coord = convert_for_check(coord);
  if (coord_of_map(coord) == -1)
    return (-1);
  if (coord_of_map2(coord) == -1)
    return (-1);
  if (coord_of_map3(coord) == -1)
    return (-1);
  map = convert_tab("map.txt");
  coord = convert_tab(pos);
  coord = convert_pos(coord);
  map = push_to_map(map, coord);
  if (coord_of_map5(map) == -1)
    return (-1);
  return (0);
}
