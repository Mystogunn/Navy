/*
** push_to_map.c for navy in /home/josselin/EPITECH/NAVY/PSU_2016_navy
** 
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
** 
** Started on  Sat Feb  4 21:39:31 2017 Josselin
** Last update Wed Feb  8 00:43:38 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

char	**push_hori(char **pos, char **map, int j, int i)
{
  int	a;

  a = 0;
  while (j !=  0)
    {
      map[(pos[i][3] - 48) + 1 + a]
	[(pos[i][2] - 48) * 2] = pos[i][0];
      a = a + 1;
      j = j - 1;
    }
  return (map);
}

char	**push_verti(char **pos, char **map, int j, int i)
{
  int	a;

  a = 0;
  while (j != 0)
    {
      map[(pos[i][3] - 48) + 1]
	[(pos[i][2] - 48) * 2 + a * 2] = pos[i][0];
      a = a + 1;
      j = j - 1;
    }
  return (map);
}

char	**push_to_map(char **map, char **pos)
{
  int	i;
  int	j;

  i = 0;
  while (pos[i] != NULL)
    {
      j = (pos[i][0] - 48);
      if (pos[i][2] == pos[i][5])
	map = push_hori(pos, map, j, i);
      if (pos[i][3] == pos[i][6])
	map = push_verti(pos, map, j, i);
      i = i + 1;
    }
  return (map);
}
