/*
** convert_pos.c for convert_pos.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sat Feb  4 19:33:51 2017 Josselin
** Last update Fri Feb 17 19:13:28 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

char	**convert_pos4(char **pos)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (pos[i] != NULL)
    {
      while (pos[i][j] != 0)
	{
	  if (pos[i][j] >= 'a' && pos[i][j] <= 'h')
	    pos[i][j] = pos[i][j] - 32;
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  return (pos);
}

char    **convert_pos3(char **pos)
{
  int   i;
  int   j;
  int   x;
  char  c;

  i = 0;
  j = 3;
  x = 6;
  while (pos[i] != NULL)
    {
      if (pos[i][j] > pos[i][x])
	{
	  c = pos[i][j];
	  pos[i][j] = pos[i][x];
	  pos[i][x] = c;
	}
      if (pos[i][j - 1] > pos[i][x - 1])
	{
	  c = pos[i][j - 1];
	  pos[i][j - 1] = pos[i][x - 1];
	  pos[i][x - 1] = c;
	}
      i = i + 1;
    }
  return (pos);
}

char    **convert_pos2(char **pos)
{
  int   i;
  int   j;
  char  c;

  i = 0;
  j = 0;
  pos = convert_pos4(pos);
  while (pos[i] != NULL)
    {
      while (pos[i][j] != 0)
	{
	  if (pos[i][j] >= '1' && pos[i][j] <= '9'
	      && pos[i][j + 1] >= 'A' && pos[i][j + 1] <= 'H')
	    {
	      c = pos[i][j];
	      pos[i][j] = pos[i][j + 1];
	      pos[i][j + 1] = c;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  pos = convert_pos3(pos);
  return (pos);
}

char    **convert_pos(char **pos)
{
  int	x;
  int   j;

  pos = convert_pos2(pos);
  x = 0;
  j = 0;
  while (pos[x] != NULL)
    {
      while (pos[x][j] != 0)
	{
	  if (pos[x][j] >= 'A' && pos[x][j] <= 'H')
	    pos[x][j] = pos[x][j] - 16;
	  j = j + 1;
	}
      x = x + 1;
      j = 0;
    }
  return (pos);
}
