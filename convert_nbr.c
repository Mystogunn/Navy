/*
** convert_nbr.c for convert_nbr.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sun Feb  5 09:43:17 2017 Josselin
** Last update Sun Feb 19 04:46:36 2017 Josselin
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*my_revstr(char *str)
{
  int	e;
  int	f;
  int	g;
  int	h;

  f = 0;
  g = my_strlen(str) - 1;
  h = (my_strlen(str) - 1) / 2;
  while (f <= h)
    {
      e = str[f];
      str[f] = str[g];
      str[g] = e;
      f = f + 1;
      g = g - 1;
    }
  return (str);
}

char	*convert_nbr(int i)
{
  int	j;
  int	x;
  char	*str;

  if ((str = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  x = 0;
  while (1)
    {
      j = i % 10;
      str[x] = j + 48;
      i = i / 10;
      x = x + 1;
      if (i < 10)
	{
	  str[x] = i + 48;
	  break;
	}
    }
  str[x + 1] = 0;
  str = my_revstr(str);
  return (str);
}
